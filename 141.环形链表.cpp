/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
       auto s = head;
       auto f = head;
       while(f!=nullptr){
        s=s->next;
        f = f->next;
        if(f==nullptr){
            return false;
        }
        f = f->next;

        if(s==f){
            return true;
        }

       }
       return false; 
    }
};
// @lc code=end

