#include "gtest/gtest.h"

#include <string>

using std::string;

bool IsPalindrome(const char *s, size_t len) {
  if (len > 1) {
    auto mid = len >> 1;
    for (auto i = 0; i < mid; i++) {
      if (s[i] != s[len - i - 1])
        return false;
    }
  }
  return true;
}

// 给你一个字符串 s，找到 s 中最长的回文子串。
// 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
string longestPalindrome(string s) {
  if (s.length() == 1)
    return s;

    const char *max_begin = s.data();
    size_t max = 1;

  for (auto i = 0; i < s.length(); i++) {
    for (auto j = s.length() - i; j > 0; j--) {
      if (IsPalindrome(s.data() + i, j)) {
        if (j > max) {
            max_begin = s.data() + i;
            max = j;
        }
      }
    }
  }

  return string(max_begin, max);
}

TEST(T005_LongestPalindromicSubstring, OneWord) {
  ASSERT_EQ(longestPalindrome("a"), "a");
}

TEST(T005_LongestPalindromicSubstring, TwoWord) {
  ASSERT_EQ(longestPalindrome("ab"), "a");
}

TEST(T005_LongestPalindromicSubstring, ThreeWord) {
  ASSERT_EQ(longestPalindrome("abc"), "a");
}

TEST(T005_LongestPalindromicSubstring, TwoWordWithTwoPalindrome) {
  ASSERT_EQ(longestPalindrome("aa"), "aa");
}

TEST(T005_LongestPalindromicSubstring, FourWordWithTwoPalindrome) {
  ASSERT_EQ(longestPalindrome("cbbd"), "bb");
}

TEST(T005_LongestPalindromicSubstring, Example1) {
  ASSERT_EQ(longestPalindrome("babad"), "bab");
}