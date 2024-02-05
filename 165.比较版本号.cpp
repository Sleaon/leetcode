/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
#include <cstdint>
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.size() || j<version2.size()){
            uint64_t v1=0,v2=0;
            while(i<version1.size()&& version1[i]!='.'){
                v1 = v1*10+version1[i]-'0';
                ++i;
            }
            ++i;

            while(j<version2.size()&& version2[j]!='.'){
                v2 = v2*10+version2[j]-'0';
                ++j;
            }
            ++j;
            if(v1>v2){
                return 1;
            }else if(v1<v2){
                return -1;
            }

        }
        return 0;
    }
};
// @lc code=end

