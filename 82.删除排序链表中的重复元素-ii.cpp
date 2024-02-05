/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode root(0,head);
        auto current = &root;
        ListNode* delete_head = nullptr;
        ListNode* delete_tail= nullptr;
        while(current->next!=nullptr && current->next->next !=nullptr){

            if(current->next->val == current->next->next->val){
                delete_tail = current->next->next;
                while(delete_tail->next!=nullptr && delete_tail->next->val == delete_tail->val){
                    delete_tail = delete_tail->next;
                }
                current->next = delete_tail->next;
            }else{
                current = current->next;
            }
        }
        return root.next;
    }
};
// @lc code=end

