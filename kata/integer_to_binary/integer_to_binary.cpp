/*
https://www.codewars.com/kata/55606aeebf1f0305f900006f/train/c

Convert integers to binary as simple as that. You would be given an integer as a
argument and you have to return its binary form. To get an idea about how to
convert a decimal number into a binary number, visit here.

Notes: negative numbers should be handled as two's complement; assume all
numbers are integers stored using 4 bytes (or 32 bits) in any language.

Your output should ignore leading 0s.

Examples (input --> output):
    3  --> "11"
    -3 -->"11111111111111111111111111111101"

*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

std::string ToBinary(int n) {
  int pos = 0;
  char binary[32 + 1] = {};

  unsigned _n = (unsigned)n;

  if (_n == 0)
    return "0";

  while (_n) {
    auto v = _n & 1;
    binary[pos++] = '0' + v;
    _n >>= 1;
  }

  for (int i = 0; i < pos / 2; i++) {
    auto tmp = binary[i];
    binary[i] = binary[pos - i - 1];
    binary[pos - i - 1] = tmp;
  }

  return binary;
}

TEST_CASE("should_convet_0") { CHECK_EQ("0", ToBinary(0)); }
TEST_CASE("should_convet_1") { CHECK_EQ("1", ToBinary(1)); }
TEST_CASE("should_convet_2_to_10") { CHECK_EQ("10", ToBinary(2)); }
TEST_CASE("should_convet_3_to_11") { CHECK_EQ("11", ToBinary(3)); }
TEST_CASE("should_convet_4_to_100") { CHECK_EQ("100", ToBinary(4)); }
TEST_CASE("should_convet_-3") {
  CHECK_EQ("11111111111111111111111111111101", ToBinary(-3));
}
