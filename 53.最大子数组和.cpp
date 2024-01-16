/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ans=nums[0];
        int pre=0;
        for(auto&& i:nums){
            pre = max(i+pre,i);
            max_ans= max(max_ans,pre);
        }
        return max_ans;
    }
};
// @lc code=end

