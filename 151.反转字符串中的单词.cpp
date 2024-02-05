/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <string>
// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    std::string result(s.size(), ' ');
    int b = 0;
    int r_index = s.size() - 1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        if(s[b] == ' '){
            b = i+1;
            continue;
        }
        auto e = i;
        while (e != b) {
          result[r_index--] = s[--e];
        }

        r_index--;
        b = i + 1;
      }
    }
    auto e = s.size();
    while (e != b) {
      result[r_index--] = s[--e];
    }
    if( !result.empty() )
     {
         result.erase(0,result.find_first_not_of(" "));
     }
    return result;
  }
};
// @lc code=end

