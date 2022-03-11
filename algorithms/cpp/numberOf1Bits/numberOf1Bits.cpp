/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32 && n > 0; i++) {
            if (n & 0x1) {
                res++;
            }
            n >>= 1;
        }
        return res;
    }
};
