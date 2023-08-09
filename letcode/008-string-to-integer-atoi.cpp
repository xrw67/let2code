/**
https://leetcode.cn/problems/string-to-integer-atoi/

 */
#include "gtest/gtest.h"

#include <string>

using std::string;

static int myAtoi(string s) {
	static const int overflow_positive = 2147483647 / 10;

	int negative = 1;
	long long result = 0;
	int i = 0;
	for (; i < s.length(); i++) {
		char c = s[i];
		if (c != ' ')
			break;
	}

	if (s[i] == '-') {
		negative = -1;
		i++;
	}
	else if (s[i] == '+') {
		i++;
	}

	for (; s[i] != ' ' && i < s.length(); i++) {
		char c = s[i];
		if (c < '0' || c > '9')
			break;

		int n = c - '0';

		result *= 10;
		result += n;

		if (negative > 0) {
			if (result >= 2147483647) return 2147483647;
		}
		else {
			if (result >= 2147483648) return (-2147483647 - 1);
		}
	}
	return result * negative;
}

//
// Tests
//
//  "1"
//  "12"
//  "99999999999999999999"
//  "-1"
//  "-12"
//  "-999999999999999999"
//
//  " 12"

TEST(T008, OneChar) {
	ASSERT_EQ(myAtoi("1"), 1);
	ASSERT_EQ(myAtoi("2"), 2);
}

TEST(T008, NegativeOneChar) { ASSERT_EQ(myAtoi("-1"), -1); }

TEST(T008, Example1) { ASSERT_EQ(myAtoi("42"), 42); }

TEST(T008, Example2) { ASSERT_EQ(myAtoi("   -42"), -42); }

TEST(T008, Example3) { ASSERT_EQ(myAtoi("4193 with words"), 4193); }

TEST(T008, Example4) { ASSERT_EQ(myAtoi("words and 987"), 0); }
TEST(T008, Example5) { ASSERT_EQ(myAtoi("214748364701"), 2147483647); }
TEST(T008, Example6) { ASSERT_EQ(myAtoi("-21474836481"), -2147483647 - 1); }
TEST(T008, Example7) { ASSERT_EQ(myAtoi("-2147483648"), -2147483647 - 1); }
TEST(T008, Example8) { ASSERT_EQ(myAtoi("-91283472332"), -2147483647 - 1); }
