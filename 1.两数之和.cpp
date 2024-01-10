/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
// @lc code=start
#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            std::unordered_map<int, int> map;
            int i=0;
            for(auto&& n:nums){
                auto diff = target-n;
                auto it = map.find(diff);
                if(it != map.end()){
                    return {it->second,i}; 
                }else{
                    map.emplace(n,i);
                }
                i++;
            }
            return {-1,-1};
        
    }
};
// @lc code=end

