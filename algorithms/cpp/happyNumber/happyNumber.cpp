/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        while (true) {
            int res = n;
            n = 0;
            while (res > 0) {
                n += pow(res % 10, 2);
                res /= 10;
            }
            if (n == 1) return true;
            if (mp.count(n)) return false;
            else mp[n] = 1;
        }
        return false; 
    }
};
// @lc code=end


