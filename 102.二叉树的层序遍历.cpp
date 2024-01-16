/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <algorithm>
#include <stack>
#include <vector>
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
     if (root == nullptr) {
      return {};
    }
    std::vector<std::vector<int>> result;
    std::queue<TreeNode*> node_queue;
    int lay_size = 1;
    int sub_lay_size = 0;
    int count = 0;
    node_queue.push(root);
    std::vector<int> lay_node(lay_size);
    while (!node_queue.empty()) {
        auto node = node_queue.front();
        node_queue.pop();
        if(node->left!=nullptr){
            node_queue.push(node->left);
            sub_lay_size++;
        }
        if(node->right!=nullptr){
            node_queue.push(node->right);
            sub_lay_size++;
        }
        lay_node[count++] = node->val;
        if(count==lay_size){
            result.push_back(std::move(lay_node));
            lay_node.resize(sub_lay_size);
            lay_size = sub_lay_size;
            sub_lay_size=0;
            count=0;
        }
    
    }
    return result;
  }
};
// @lc code=end
