#include "gtest/gtest.h"

#include <string>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * https://leetcode.cn/problems/add-two-numbers/
 */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

  ListNode *head = nullptr;
  ListNode *tail = nullptr;
  int carry = 0;
  auto p1 = l1;
  auto p2 = l2;

  while (p1 || p2) {
    int sum = carry;
    if (p1) {
      sum += p1->val;
      p1 = p1->next;
    }
    if (p2) {
      sum += p2->val;
      p2 = p2->next;
    }

    if (sum >= 10) {
      carry = 1;
      sum -= 10;
    } else {
      carry = 0;
    }

    ListNode *newnode = new ListNode(sum);
    if (!head) {
      head = tail = newnode;
    } else {
      tail->next = newnode;
      tail = newnode;
    }
  }

  if (carry)
    tail->next = new ListNode(carry);
  return head;
}

std::string Add(const std::string &l1, const std::string &l2) {
  ListNode *head_l1 = nullptr;
  ListNode *head_l2 = nullptr;

  for (auto i : l1) {
    head_l1 = new ListNode(i - '0', head_l1);
  }

  for (auto i : l2) {
    head_l2 = new ListNode(i - '0', head_l2);
  }

  ListNode *head_sum = addTwoNumbers(head_l1, head_l2);

  std::string result;

  for (auto p = head_sum; p != nullptr; p = p->next) {
    result += p->val + '0';
  }

  return result;
}

TEST(T002_AddTwoNumbers, Zero) { EXPECT_EQ(Add("0", "0"), "0"); }

TEST(T002_AddTwoNumbers, OneAddOne) { EXPECT_EQ(Add("1", "1"), "2"); }

TEST(T002_AddTwoNumbers, ElevenAddEleven) { EXPECT_EQ(Add("11", "11"), "22"); }

TEST(T002_AddTwoNumbers, CarryOneBit) { EXPECT_EQ(Add("6", "7"), "31"); }

TEST(T002_AddTwoNumbers, Example1) { EXPECT_EQ(Add("243", "564"), "708"); }

TEST(T002_AddTwoNumbers, Example3) {
  EXPECT_EQ(Add("9999999", "9999"), "89990001");
}