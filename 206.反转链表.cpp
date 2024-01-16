/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        auto current = head;
        auto next_node = head->next;
        head->next = nullptr;
        while(next_node != nullptr){
            auto tmp = next_node->next;
            next_node->next = current;
            current = next_node;
            next_node = tmp;
        }
        return current;
    }
};
// @lc code=end

