#include <stdexcept>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

class Stack {
public:
  bool IsEmpty() const { return elements_.empty(); }

  void Push(int element) { elements_.push_back(element); }

  int Pop() {
    if (IsEmpty())
      throw std::underflow_error("pop is empty");

    auto result = elements_.back();
    elements_.pop_back();
    return result;
  }

private:
  std::vector<int> elements_;
};

TEST_SUITE_BEGIN("Stack");

class StackTest {
protected:
  Stack stack;
};

/*
    Stack
        push/push -> pop pop
 */
TEST_CASE_FIXTURE(StackTest, "create_stack_and_is_empty") {
  REQUIRE(stack.IsEmpty());
}

TEST_CASE_FIXTURE(StackTest, "can_push_one_element") {
  stack.Push(0);
  REQUIRE_FALSE(stack.IsEmpty());
}

TEST_CASE_FIXTURE(StackTest, "should_pop_except_when_is_empty") {
  REQUIRE_THROWS(stack.Pop());
}

TEST_CASE_FIXTURE(StackTest, "can_push_and_pop_then_is_empty") {
  stack.Push(0);
  stack.Pop();
  REQUIRE(stack.IsEmpty());
}

TEST_CASE_FIXTURE(StackTest, "can_push_two_element_and_pop_one_element") {
  stack.Push(0);
  stack.Push(0);
  stack.Pop();
  REQUIRE_FALSE(stack.IsEmpty());
}

TEST_CASE_FIXTURE(StackTest, "must_pop_right_value") {
  stack.Push(88);
  stack.Push(99);
  REQUIRE_EQ(99, stack.Pop());
  REQUIRE_EQ(88, stack.Pop());
}

TEST_SUITE_END;