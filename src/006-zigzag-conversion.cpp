#include "gtest/gtest.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

//
// https://leetcode.cn/problems/zigzag-conversion/
// 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z
// 字形排列。
//

static string convert(string s, int numRows) {
  vector<string> rows(numRows);
  bool move_down = true;
  int next_row = 0;
  int next_column = 0;

  if (numRows == 1)
    return s;

  for (auto c : s) {
    string &cell = rows[next_row];
    cell += c;

    // choose next cell
    if (move_down) {
      if (next_row == (numRows - 1)) {
        next_row--;
        next_column++;
        move_down = false; // start moveup
      } else {
        next_row++;
      }
    } else {
      if (next_row == 0) {
        move_down = true;
        next_row = 1;
      } else {
        next_row--;
        next_column++;
      }
    }
  }

  // ouput
  string result;
  for (auto row : rows) {
    for (auto c : row) {
      result += c;
    }
  }

  return result;
}

TEST(T006_ZigzagConversion, OneLine) {
  EXPECT_EQ(convert("A", 1), "A");
  EXPECT_EQ(convert("AB", 1), "AB");
}

TEST(T006_ZigzagConversion, TwoLine) {
  EXPECT_EQ(convert("A", 2), "A");
  EXPECT_EQ(convert("AB", 2), "AB");
}

TEST(T006_ZigzagConversion, Example1) {
  EXPECT_EQ(convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}

TEST(T006_ZigzagConversion, Example2) {
  EXPECT_EQ(convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}