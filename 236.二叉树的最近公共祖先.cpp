/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr){
            return false;
        }
        bool found = false;
        if(root->val==p->val || root->val==q->val){
            found = true;
        }
        auto lfound = dfs(root->left,p,q);
        auto rfound = dfs(root->right,p,q);
        auto found_father = found?(lfound||rfound):(lfound&&rfound);
        if(found_father){
            ans = root;
        }
        return found || lfound || rfound;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
// @lc code=end

