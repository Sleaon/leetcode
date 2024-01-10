/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c = 0;
    auto root = new ListNode();
    auto head = root;
    while (l1 != nullptr && l2 != nullptr) {
      auto sum = l1->val + l2->val + c;
      if (sum / 10 == 1) {
        sum -= 10;
        c = 1;
      } else {
        c = 0;
      }
      head->next = new ListNode(sum);
      l1 = l1->next;
      l2 = l2->next;
      head = head->next;
    }
    while (l1 != nullptr) {
      if (c == 0) {
        head->next = l1;
        break;
      }
      auto sum = l1->val + c;
      if (sum / 10 == 1) {
        sum -= 10;
        c = 1;
      } else {
        c = 0;
      }
      head->next = new ListNode(sum);
      l1 = l1->next;
      head = head->next;
    }

    while (l2 != nullptr) {
      if (c == 0) {
        head->next = l2;
        break;
      }
      auto sum = l2->val + c;
      if (sum / 10 == 1) {
        sum -= 10;
        c = 1;
      } else {
        c = 0;
      }
      head->next = new ListNode(sum);
      l2 = l2->next;
      head = head->next;
    }
    if (c == 1) {
      head->next = new ListNode(1);
    }

    return root->next;
  }
};
// @lc code=end
