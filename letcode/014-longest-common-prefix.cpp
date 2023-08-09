//
// https://leetcode.cn/problems/longest-common-prefix/
//
// 编写一个函数来查找字符串数组中的最长公共前缀。
//
// 如果不存在公共前缀，返回空字符串 ""。
//
#include "gmock/gmock.h"

#include <string>
#include <vector>

namespace {

using std::string;
using std::vector;

string longestCommonPrefix(vector<string> &strs) {
  auto &base = strs[0];
  auto max = base.length();

  for (auto s : strs) {
    if (s.length() > max)
      max = s.length();
  }

  for (string::size_type i = 1; i < strs.size(); i++) {
    auto &s = strs[i];
    for (string::size_type j = 0; j < max; j++) {
      if (j == s.length() || base[j] != s[j]) {
        max = j;
        break;
      }
    }
  }
  return base.substr(0, max);
}

TEST(T014, Example1) {
  vector<string> strs({"flower", "flow", "flight"});
  ASSERT_EQ(longestCommonPrefix(strs), "fl");
}

TEST(T014, Example2) {
  vector<string> strs({"dog", "racecar", "car"});
  ASSERT_EQ(longestCommonPrefix(strs), "");
}

TEST(T014, Example3) {
  vector<string> strs({"ab", "a"});
  ASSERT_EQ(longestCommonPrefix(strs), "a");
}

} // namespace