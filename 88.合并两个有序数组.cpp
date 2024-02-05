/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto it = nums1.rbegin();
        m--;
        n--;
        while(m>-1 && n>-1){
            if(nums1[m]> nums2[n]){
                *it = nums1[m--];
            }else{
                *it = nums2[n--];
            }
            ++it;
        }
        while(m>-1){
            *it = nums1[m--];
            ++it;
        }
        while(n>-1){
            *it = nums2[n--];
            ++it;
        }
    }
};
// @lc code=end

