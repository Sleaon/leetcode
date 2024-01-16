/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
  void reverse(ListNode* head, ListNode* tail) {
    if (head == nullptr) {
      return;
    }
    auto current = head;
    auto next_node = head->next;
    while (next_node != nullptr && current != tail) {
      auto tmp = next_node->next;
      next_node->next = current;
      current = next_node;
      next_node = tmp;
    }
    head->next = next_node;
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode HHead;
    HHead.next = head;
    auto sub_tail = &HHead;
    while (head != nullptr) {
        auto current =sub_tail;
        for(int i =0;i<k;i++){
            current = current->next;
            if(current==nullptr){
                return HHead.next;
            }
        }
        reverse(head,current);
        sub_tail->next = current;
        sub_tail = head;
        head = head ->next;
    }
    return HHead.next;
  }
};
// @lc code=end
