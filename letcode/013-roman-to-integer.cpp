//
// https://leetcode.cn/problems/roman-to-integer/
//
#include "gmock/gmock.h"

#include <string>

namespace {

using std::string;

int consume(const char **p) {
  static const struct {
    int num;
    const std::string roman;
  } carrys[] = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
                {5, "V"},    {4, "IV"},   {1, "I"}

  };

  const char *tmp = *p;
  for (auto i : carrys) {
    if (!strncmp(tmp, i.roman.c_str(), i.roman.length())) {
      *p += i.roman.length();
      return i.num;
    }
  }
  return 0;
}

int romanToInt(string s) {
  int result = 0;
  const char *p = s.c_str();
  while (*p != '\0') {
    int n = consume(&p);
    if (!n)
      return 0;
    result += n;
  }
  return result;
}

TEST(T013, Example1) { EXPECT_EQ(romanToInt("III"), 3); }
TEST(T013, Example2) { EXPECT_EQ(romanToInt("IV"), 4); }
TEST(T013, Example3) { EXPECT_EQ(romanToInt("IX"), 9); }
TEST(T013, Example4) { EXPECT_EQ(romanToInt("LVIII"), 58); }
TEST(T013, Example5) { EXPECT_EQ(romanToInt("MCMXCIV"), 1994); }

} // namespace