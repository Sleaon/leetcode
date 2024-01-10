/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <bitset>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s.size() == 0) return 0;
         std::bitset<128> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.test(s[i])){
                lookup.set(s[left],false);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.set(s[i]);
    }
        return maxStr;
    }
};
// @lc code=end

