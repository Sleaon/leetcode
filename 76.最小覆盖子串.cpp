/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
#include <string_view>
#include <unordered_map>
// @lc code=start
class Solution {
  inline bool IsSub(std::unordered_map<char, int>& count) {
    for (auto&& [_, i] : count) {
      if (i > 0) {
        return false;
      }
    }
    return true;
  }
  inline void UpdateMinSub(std::string& ans, std::string_view sub) {
    if (ans.empty() || sub.size() < ans.size()) {
      ans = sub;
    }
  }

 public:
  string minWindow(string s, string t) {
    std::unordered_map<char, int> count;
    for (auto& c : t) {
      ++count[c];
    }
    std::string ans;
    int l = 0, r = 0;
    while (r < s.size()) {
      auto it = count.find(s[r]);
      if (it != count.end()) {
        --it->second;
        if (it->second == 0) {
          while (l <= r && IsSub(count)) {
            UpdateMinSub(ans, std::string_view(s).substr(l, r - l + 1));
            auto itl = count.find(s[l++]);
            if (itl != count.end()) {
              ++itl->second;
              if (itl->second > 0) {
                break;
              }
            }
          }
        }
      }
      r++;
    }
    return ans;
  }
};
// @lc code=end
