/**
https://leetcode.cn/problems/palindrome-number/

给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 */
#include "gtest/gtest.h"

static int reverse(int x) {
  static const int overflow_positive = 2147483647 / 10;
  static const int overflow_negative = overflow_positive * -1;

  int result = 0;
  while (x != 0) {
    if (result > overflow_positive || result < overflow_negative) return 0;
    result *= 10;
    result += (x % 10);
    x /= 10;
  }
  return result;

}

static bool isPalindrome(int x) {
  if (x < 0) return false;
  return x == reverse(x);
}

TEST(T009, OneNumber) {
  ASSERT_TRUE(isPalindrome(1));
  ASSERT_TRUE(isPalindrome(2));
}

TEST(T009, Example1) { ASSERT_TRUE(isPalindrome(121)); }

TEST(T009, Example2){ASSERT_FALSE(isPalindrome(-121));}

TEST(T009, Example3){ASSERT_FALSE(isPalindrome(10));}

TEST(T009, Example4) { ASSERT_FALSE(isPalindrome(123)); }

TEST(T009, Example5) { ASSERT_FALSE(isPalindrome(1234567899)); }