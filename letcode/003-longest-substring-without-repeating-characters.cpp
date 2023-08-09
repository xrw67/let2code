#include "gtest/gtest.h"

#include <string>

using std::string;

//
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
//
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
//
// s 由英文字母、数字、符号和空格组成
int lengthOfLongestSubstring(string s) {
  const char *end = s.data() + s.length();
  const char *max = nullptr;
  const char *max_end = nullptr;
  const char *cur = s.data();
  const char *cur_end = cur;

  for (auto i = s.data(); i < end; i++) {
    for (auto j = cur; j < cur_end; j++) {
      if (*j == *i) {
        if ((cur_end - cur) > (max_end - max)) {
          max = cur;
          max_end = cur_end;
        }
        cur = j + 1;
        break;
      }
    }
    cur_end = i + 1;
  }

  auto a = cur_end - cur;
  auto b = max_end - max;
  return a > b ? a : b;
}

int lengthOfLongestSubstring_2(string s) {
  string max;
  string current;

  for (int i = 0; i < s.length(); i++) {
    auto c = s[i];

    auto pos = current.find(c);
    if (pos != current.npos) {
      if (current.length() > max.length()) {
        max = current;
      }
      current = current.substr(pos + 1);
    }
    current += c;
  }

  auto a = current.length();
  auto b = max.length();
  return a > b ? a : b;
}

TEST(T003_LongestSubstringWithoutRepeatingCHaracters, OneWord) {
  EXPECT_EQ(lengthOfLongestSubstring("a"), 1);
}

TEST(T003_LongestSubstringWithoutRepeatingCHaracters, TwoWord) {
  EXPECT_EQ(lengthOfLongestSubstring("ab"), 2);
}

TEST(T003_LongestSubstringWithoutRepeatingCHaracters, RepeatOneWord) {
  EXPECT_EQ(lengthOfLongestSubstring("aa"), 1);
}

TEST(T003_LongestSubstringWithoutRepeatingCHaracters, RepeatTwoWord) {
  EXPECT_EQ(lengthOfLongestSubstring("aba"), 2);
}

TEST(T003_LongestSubstringWithoutRepeatingCHaracters, Example1) {
  EXPECT_EQ(lengthOfLongestSubstring("abcabcbb"), 3);
}

TEST(T003_LongestSubstringWithoutRepeatingCHaracters, Example2) {
  EXPECT_EQ(lengthOfLongestSubstring("bbbbb"), 1);
}

TEST(T003_LongestSubstringWithoutRepeatingCHaracters, Example3) {
  EXPECT_EQ(lengthOfLongestSubstring("pwwkew"), 3);
}

TEST(T003_LongestSubstringWithoutRepeatingCHaracters, Example188) {
  EXPECT_EQ(lengthOfLongestSubstring("dvdf"), 3);
}