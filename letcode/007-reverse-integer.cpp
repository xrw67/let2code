#include "gtest/gtest.h"

/*
https://leetcode.cn/problems/reverse-integer/

给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。

*/

static int reverse(int x) {
	static const int overflow_positive = 2147483647 / 10;
	static const int overflow_negative = overflow_positive * -1;

	int result = 0;
	while (x != 0) {
		if (result > overflow_positive || result < overflow_negative)
			return 0;
		result *= 10;
		result += (x % 10);
		x /= 10;
	}
	return result;
}

TEST(T007, OverflowPositiveNumber) {
	EXPECT_EQ(reverse(1534236469), 0);
}

TEST(T007, Zero) {
	EXPECT_EQ(reverse(0), 0);
}

TEST(T007, OnePositiveNumber) {
	EXPECT_EQ(reverse(1), 1);
}

TEST(T007, TwoPositiveNumber) {
	EXPECT_EQ(reverse(12), 21);
}


TEST(T007, Example1) {
	EXPECT_EQ(reverse(123), 321);
}

TEST(T007, OneNegativeNumber) {
	EXPECT_EQ(reverse(-1), -1);
}

TEST(T007, TwoNegativeNumber) {
	EXPECT_EQ(reverse(-12), -21);
}


TEST(T007, Example2) {
	EXPECT_EQ(reverse(-123), -321);
}

TEST(T007, Example3) {
	EXPECT_EQ(reverse(120), 21);
}