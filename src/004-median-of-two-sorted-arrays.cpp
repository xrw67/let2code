#include "gtest/gtest.h"
#include <vector>

using std::vector;

/*
https://leetcode.cn/problems/median-of-two-sorted-arrays/

给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1
和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log(m + n)) 。
*/

// TODO: 更好的方法
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  const int size1 = nums1.size();
  const int size2 = nums2.size();
  const int *nums[2] = {nums1.data(), nums2.data()};
  int median = (size1 + size2) / 2;
  int buf[2] = {0, 0};
  int buf_idx = 0;

  for (int i1 = 0, i2 = 0, pos = 0; pos <= median; pos++) {
    if (i1 < size1 && i2 < size2) {
      if (nums[0][i1] < nums[1][i2]) {
        buf[buf_idx] = nums[0][i1++];
      } else {
        buf[buf_idx] = nums[1][i2++];
      }
    } else if (i1 < size1) {
      buf[buf_idx] = nums[0][i1++];
    } else {
      buf[buf_idx] = nums[1][i2++];
    }
    buf_idx = (buf_idx + 1) & 1;
  }

  if (((size1 + size2) & 1) == 0)
    return (buf[0] + buf[1]) / 2.0;
  else
    return (double)buf[(buf_idx + 1) & 1];
}

TEST(T004_MedianOfTwoSortedArrays, Zero) {
  vector<int> nums1({0});
  vector<int> nums2({0});
  EXPECT_EQ(findMedianSortedArrays(nums1, nums2), 0.0);
}

TEST(T004_MedianOfTwoSortedArrays, Two) {
  vector<int> nums1({1});
  vector<int> nums2({2});
  EXPECT_EQ(findMedianSortedArrays(nums1, nums2), 1.5);
}

TEST(T004_MedianOfTwoSortedArrays, Number1Islonger) {
  vector<int> nums1({10, 20, 30, 40});
  vector<int> nums2({1, 2, 3});
  EXPECT_EQ(findMedianSortedArrays(nums1, nums2), 10.0);
}

TEST(T004_MedianOfTwoSortedArrays, Example1) {
  vector<int> nums1({1, 3});
  vector<int> nums2({2});
  EXPECT_EQ(findMedianSortedArrays(nums1, nums2), 2.0);
}

TEST(T004_MedianOfTwoSortedArrays, Example2) {
  vector<int> nums1({1, 2});
  vector<int> nums2({3, 4});
  EXPECT_EQ(findMedianSortedArrays(nums1, nums2), 2.5);
}