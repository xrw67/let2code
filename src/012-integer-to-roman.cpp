///
/// https://leetcode.cn/problems/integer-to-roman/
///
#include "gmock/gmock.h"

#include <string>

namespace {

using std::string;

string intToRoman(int num) {
  static const struct {
    int num;
    const char *roman;
  } carrys[] = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                  {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
                  {5, "V"},    {4, "IV"},   {1, "I"}

  };

  string result;

  while (num > 0) {
    for (auto i : carrys) {
      if (num >= i.num) {
        result += i.roman;
        num -= i.num;
        break;
      }
    }
  }

  return result;
}

TEST(T012, Example1) { EXPECT_EQ(intToRoman(3), "III"); }
TEST(T012, Example2) { EXPECT_EQ(intToRoman(4), "IV"); }
TEST(T012, Example3) { EXPECT_EQ(intToRoman(9), "IX"); }
TEST(T012, Example4) { EXPECT_EQ(intToRoman(58), "LVIII"); }
TEST(T012, Example5) { EXPECT_EQ(intToRoman(1994), "MCMXCIV"); }

} // namespace