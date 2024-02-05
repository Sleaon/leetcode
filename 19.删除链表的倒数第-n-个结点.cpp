/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode root(0,head);
        auto f = head;
        auto s = head;
        auto c = &root;
        for(int i=0;i<n;++i){
            f = f->next;
        }
        while(f!=nullptr){
            f= f->next;
            s= s->next;
            c = c->next;
        }
        c->next = s->next;
        return root.next;
    }
};
// @lc code=end

