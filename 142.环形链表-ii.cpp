/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    auto s = head;
    auto f = head;
    while (f != nullptr) {
      s = s->next;
      f = f->next;
      if (f == nullptr) {
        return nullptr;
      }
      f = f->next;

      if (s == f) {
        f = head;
        while (s != f) {
          s = s->next;
          f = f->next;
        }
        return s;
      }
    }
    return nullptr;
  }
};
// @lc code=end
