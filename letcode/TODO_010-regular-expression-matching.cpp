//
// https://leetcode.cn/problems/regular-expression-matching/
//
// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
//
// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
//
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
//
#include <string>
#include <gmock/gmock.h>

using std::string;


static bool isMatch(string s, string p) {
    const char* s_ptr = s.c_str();
    const char* p_ptr = p.c_str();

    while (*p_ptr) {
        if (p_ptr[1] == '*') {
            char c = *p_ptr;
            p_ptr += 2;

            while (*s_ptr) {
                if (isMatch(string(s_ptr), string(p_ptr)))
                    return true;
                if (*s_ptr == c || c == '.')
                    s_ptr++;
                else
                    break;
            }
            continue;
        }

        if (*p_ptr == '.') {
            s_ptr++;
            p_ptr++;
            continue;
        }

        if (*s_ptr != *p_ptr) {
            return false;
        }

        s_ptr++;
        p_ptr++;
    }
    return *s_ptr == *p_ptr;
}

TEST(T010, WithDot) {
    ASSERT_TRUE(isMatch("aabec", "a.b.c"));
}

TEST(T010, Example1) {
    ASSERT_FALSE(isMatch("aa", "a"));
}

TEST(T010, Example2) {
    ASSERT_TRUE(isMatch("aa", "a*"));
}

TEST(T010, Example3) {
    ASSERT_TRUE(isMatch("aa", ".*"));
}

TEST(T010, Example4) {
    ASSERT_TRUE(isMatch("aab", "c*a*b"));
}

TEST(T010, Example5) {
    ASSERT_TRUE(isMatch("aaa", "a*a"));
}

TEST(T010, Example6) {
    ASSERT_TRUE(isMatch("a", "ab*"));
}

TEST(T010, Example7) {
    ASSERT_FALSE(isMatch("a", ".*..a*"));
}