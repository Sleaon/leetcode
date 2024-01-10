/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <cstddef>
#include <exception>
#include <stdexcept>
class Solution {
  class DpArray {
   public:
    explicit DpArray(size_t size) : size_(size), dp_(size * size, 0) {}
    bool IsTrue(size_t i, size_t j) const { return dp_[Index(i, j)] == 1; }
    void Set(size_t i, size_t j) { dp_[Index(i, j)] = 1; }

   private:
    size_t Index(size_t i, size_t j) const {
      if (i >= size_ || j >= size_) {
        throw std::range_error("out of range");
      }
      return i * size_ + j;
    }
    size_t size_;
    vector<char> dp_;
  };

 public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n < 2) {
      return s;
    }

    int maxLen = 1;
    int begin = 0;
    // dp[i][j] 表示 s[i..j] 是否是回文串
    DpArray dp(n);
    // 初始化：所有长度为 1 的子串都是回文串
    for (int i = 0; i < n; i++) {
      dp.Set(i, i);
    }
    // 递推开始
    // 先枚举子串长度
    for (int L = 2; L <= n; L++) {
      auto max = n - L + 1;
      // 枚举左边界
      for (int i = 0; i < max; i++) {
        // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
        int j = L + i - 1;

        if (s[i] == s[j]) {
          if (j - i < 3) {
            dp.Set(i, j);
            auto len = j - i + 1;
            if (len > maxLen) {
              maxLen = len;
              begin = i;
            }
          } else {
            if (dp.IsTrue(i + 1, j - 1)) {
              dp.Set(i, j);
              auto len = j - i + 1;
              if (len > maxLen) {
                maxLen = len;
                begin = i;
              }
            }
          }
        }
      }
    }
    return s.substr(begin, maxLen);
  }
};
// @lc code=end
