///
/// http://butunclebob.com/ArticleS.UncleBob.TheBowlingGameKata
/// https://kata-log.rocks/bowling-game-kata
///
/// ## 规则
/// 1. 一局10轮
/// 2. 每轮两次机会击倒全部10个球
///    - 如果第一次就全中（strike），得分 = 10 + 后两次击倒的瓶数
///    - 如果未全中，则再打一球（spare），得分 = 10 + 后一次击倒的瓶数
///    - 如果两次都未击倒所有瓶（miss），得分 = 两次击倒的的球瓶之和
/// 3. 第10轮有三次击球机会
///    - 如果第一次全中，还可继续投完剩余两球
///    - 如果补中，则继续投完剩余一球
///    - 如果两次都未击倒全部球，则比赛结束
/// 4. 分数最高的胜利
///

#include "gtest/gtest.h"

#include <array>

namespace {

class Game {
public:
  void Roll(int pins) { rolls_[current_roll_++] = pins; }

  int Score() {
    int score = 0;
    int frame_index = 0;
    for (int frame = 0; frame < 10; frame++) {
      if (IsStrike(frame_index)) {
        score += 10 + StrikeBonus(frame_index);
        frame_index++;
      } else if (IsSpare(frame_index)) {
        score += 10 + SpareBonus(frame_index);
        frame_index += 2;
      } else {
        score += SumOfBallsInFrame(frame_index);
        frame_index += 2;
      }
    }

    return score;
  }

private:
  bool IsStrike(int frame_index) { return rolls_[frame_index] == 10; }

  bool IsSpare(int frame_index) {
    return rolls_[frame_index] + rolls_[frame_index + 1] == 10;
  }

  int SumOfBallsInFrame(int frame_index) {
    return rolls_[frame_index] + rolls_[frame_index + 1];
  }

  int SpareBonus(int frame_index) { return rolls_[frame_index + 2]; }

  int StrikeBonus(int frame_index) {
    return rolls_[frame_index + 1] + rolls_[frame_index + 2];
  }

  std::array<int, 21> rolls_ = {};
  int current_roll_ = 0;
};

struct BowlingGameTest : public ::testing::Test {
  Game g;

  void RollMany(int n, int pins) {
    for (int i = 0; i < n; i++)
      g.Roll(pins);
  }

  void RollSpare() {
    g.Roll(5);
    g.Roll(5);
  }
};

TEST_F(BowlingGameTest, test_gutter_game) {
  RollMany(20, 0);
  ASSERT_EQ(0, g.Score());
}

TEST_F(BowlingGameTest, test_all_ones) {
  RollMany(20, 1);
  ASSERT_EQ(20, g.Score());
}

TEST_F(BowlingGameTest, test_one_spare) {
  RollSpare();
  g.Roll(3);
  RollMany(17, 0);
  ASSERT_EQ(16, g.Score());
}

TEST_F(BowlingGameTest, test_one_strike) {
  g.Roll(10);
  g.Roll(3);
  g.Roll(4);

  RollMany(16, 0);
  ASSERT_EQ(24, g.Score());
}

TEST_F(BowlingGameTest, test_perfect_game) {
  RollMany(12, 10);
  ASSERT_EQ(300, g.Score());
}

} // namespace
