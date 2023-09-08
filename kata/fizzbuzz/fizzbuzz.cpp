/**
给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组
answer（下标从 1 开始）返回结果，其中：

answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
answer[i] == "Fizz" 如果 i 是 3 的倍数。
answer[i] == "Buzz" 如果 i 是 5 的倍数。
answer[i] == i （以字符串形式）如果上述条件全不满足。


示例 1：

输入：n = 3
输出：["1","2","Fizz"]
示例 2：

输入：n = 5
输出：["1","2","Fizz","4","Buzz"]
示例 3：

输入：n = 15
输出：["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <vector>

namespace {

using std::string;
using std::vector;

string fizzBuzzOne(int n) {
  string result;

  if (n % 3 == 0)
    result += "Fizz";
  if (n % 5 == 0)
    result += "Buzz";

  return result.empty() ? std::to_string(n) : result;
}

vector<string> fizzBuzz(int n) {
  vector<string> result;

  for (int i = 1; i <= n; i++)
    result.push_back(fizzBuzzOne(i));
  return result;
}

// to do
// When 3的倍数, Then Fizz
// WHen 5的倍数, Then Buzz

TEST_CASE("should_print_Fizz_when_mod_by_3") {
  CHECK_EQ("Fizz", fizzBuzzOne(6));
}

TEST_CASE("should_print_Buzz_when_mod_by_5") {
  CHECK_EQ("Buzz", fizzBuzzOne(10));
}

TEST_CASE("should_print_FizBuzz_when_mod_by_3_and_5") {
  CHECK_EQ("FizzBuzz", fizzBuzzOne(30));
}

TEST_CASE("should_print_self_when_not_mod_by_3_or_5") {
  CHECK_EQ("17", fizzBuzzOne(17));
}

} // namespace