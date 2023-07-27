/**
https://leetcode.cn/problems/palindrome-number/
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