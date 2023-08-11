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

struct Game {
  int rolls[21] = {};
  int current_roll = 0;

  void roll(int pins) { rolls[current_roll++] = pins; }

  int score() {
    int score = 0;
    int frameIndex = 0;

    for (int frame = 0; frame < 10; frame++) {
      if (isStrike(frameIndex)) {
        score += 10 + strikeBonus(frameIndex);
        frameIndex++;
      } else if (isSpare(frameIndex)) {
        score += 10 + sapreBonus(frameIndex);
        frameIndex += 2;
      } else {
        score += sumOfBallsInFrame(frameIndex);
        frameIndex += 2;
      }
    }
    return score;
  }

  bool isSpare(int frameIndex) {
    return rolls[frameIndex] + rolls[frameIndex + 1] == 10;
  }

  bool isStrike(int frameIndex) { return rolls[frameIndex] == 10; }

  int sumOfBallsInFrame(int frameIndex) {
    return rolls[frameIndex] + rolls[frameIndex + 1];
  }

  int sapreBonus(int frameIndex) { return rolls[frameIndex + 2]; }

  int strikeBonus(int frameIndex) {
    return rolls[frameIndex + 1] + rolls[frameIndex + 2];
  }
};

struct BowlingGameTest : public ::testing::Test {
  Game g;

  void rollMany(int n, int pins) {
    for (int i = 0; i < n; i++) {
      g.roll(pins);
    }
  }

  void rollSpare() {
    g.roll(5);
    g.roll(5);
  }

  void rollStrike() { g.roll(10); }
};

TEST_F(BowlingGameTest, testGutterGame) {

  rollMany(20, 0);

  ASSERT_EQ(0, g.score());
}

TEST_F(BowlingGameTest, testAllOnes) {

  rollMany(20, 1);

  ASSERT_EQ(20, g.score());
}

TEST_F(BowlingGameTest, testOneSapre) {
  rollSpare();
  g.roll(3);
  rollMany(17, 0);
  ASSERT_EQ(16, g.score());
}

TEST_F(BowlingGameTest, testOneStrike) {
  rollStrike();
  g.roll(3);
  g.roll(4);
  rollMany(16, 0);
  ASSERT_EQ(24, g.score());
}

TEST_F(BowlingGameTest, testPerfectGame) {
  rollMany(12, 10);
  ASSERT_EQ(300, g.score());
}

} // namespace
