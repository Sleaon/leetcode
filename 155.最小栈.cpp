/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <stack>
#include <vector>
class MinStack {
    std::stack<int> value_stack_;
    std::vector<int> min_stack_;
public:
    MinStack():value_stack_(),min_stack_() {
        min_stack_.reserve(10);
    }
    
    void push(int val) {
        value_stack_.push(val);
        if(min_stack_.empty() || min_stack_.back() >= val){
            min_stack_.emplace_back(val);
        }
    }
    
    void pop() {
        auto value = value_stack_.top();
        value_stack_.pop();
        if(value == min_stack_.back()){
            min_stack_.pop_back();
        }
    }
    
    int top() {
        return value_stack_.top();
    }
    
    int getMin() {
        return min_stack_.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

