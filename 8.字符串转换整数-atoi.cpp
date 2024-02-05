/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <array>
#include <cctype>
#include <cstdint>
#include <limits>
class Solution {
  enum Status { kStatus, kSigned, kNumber, kEnd };
  constexpr static std::array<std::array<Status, 4>, 3> table = {
      kStatus, kSigned, kNumber, kEnd, kEnd,    kEnd,
      kNumber, kEnd,    kEnd,    kEnd, kNumber, kEnd};
  Status ToStatus(char c) {
    if (std::isspace(c)) {
      return kStatus;
    } else if (c == '+' || c == '-') {
      return kSigned;
    } else if (std::isdigit(c)) {
      return kNumber;
    } else {
      return kEnd;
    }
  }

  Status StatusTransfer(Status current, char c) {
    return table[current][ToStatus(c)];
  }

 public:
  int myAtoi(string s) {
    uint64_t r = 0;
    int sign = 1;
    Status cs = kStatus;
    for (auto&& c : s) {
      cs = StatusTransfer(cs, c);
      if (cs == kNumber) {
        r = r * 10 + c - '0';
        if (r > std::numeric_limits<int>::max()) {
          if (sign == 1) {
            r = std::numeric_limits<int>::max();
          } else {
            r = std::numeric_limits<int>::min();
          }
          break;
        }
        continue;

      } else if (cs == kSigned) {
        sign *= c == '-' ? -1 : 1;
        continue;
      } else if (cs == kEnd) {
        break;
      }
    }
    if (r > 0) {
      r *= sign;
    }
    return r;
  }
};
// @lc code=end
