/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0){
            return {""};
        }
        std::vector<std::string> brackets;
        for(int i=0;i<n;++i){
            auto left_list= generateParenthesis(i);
            auto right_list= generateParenthesis(n-i-1);
            for(auto&& left:left_list){
                for(auto&& right :right_list){
                    brackets.emplace_back("("+left+")"+right);
                }
            }
        }
        return brackets;
    }
};
// @lc code=end

