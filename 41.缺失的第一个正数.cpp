/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] != (i + 1)) {
        if (nums[i] < nums.size() && nums[i] > 0) {
          if (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
            continue;
          }
        }
      }
      ++i;
    }
    for (int j = 0; j < nums.size(); ++j) {
      if (nums[j] != (j + 1)) {
        return j + 1;
      }
    }
    return nums.size() + 1;
  }
};
// @lc code=end