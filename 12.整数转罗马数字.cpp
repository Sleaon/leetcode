/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <string>
#include <array>
// @lc code=start
constexpr std::array<const char*,4> thousands = {"", "M", "MM", "MMM"};
constexpr std::array<const char*,10> hundreds  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
constexpr std::array<const char*,10> tens      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
constexpr  std::array<const char*,10> ones      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

class Solution {
public:
    string intToRoman(int num) {
        return string(thousands[num / 1000]) + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};

// @lc code=end

