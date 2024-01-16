/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stack>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for(auto&& c:s){
            switch (c) {
                case '(':
                case '{':
                case '[':
                stack.push(c);
                break;
                case ')':
                if(!stack.empty() && stack.top()=='('){
                    stack.pop();
                }else{
                    return false;
                }
                break;
                case '}':
                if(!stack.empty() &&stack.top()=='{'){
                    stack.pop();
                }else{
                    return false;
                }
                break;
                case ']':
                if(!stack.empty() &&stack.top()=='['){
                    stack.pop();
                }else{
                    return false;
                }
                break;
            
            }
        }
        if(stack.empty()){
        return true;

        }else{
            return false;
        }

    }
};
// @lc code=end

