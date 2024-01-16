/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <cstddef>
class Solution {
 public:
  int maxArea(vector<int>& height) {
    size_t l = 0;
    size_t r = height.size() - 1;
    int max = 0;
    while (l < r) {
      int height_l = height[l];
      int height_r = height[r];
      int area = std::min(height_l, height_r) * (r - l);
      max = std::max(max, area);
      if (height_l < height_r) {
        while (l < r) {
          if (height[l] > height_l) {
            break;
          }
          l++;
        }
      } else {
        while (l < r) {
          if (height[r] > height_r) {
            break;
          }
          r--;
        }
      }
    }
    return max;
  }
};
// @lc code=end
