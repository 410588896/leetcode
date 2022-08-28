/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 */

// @lc code=start
class Solution {
private:
    int getZeroNum(long x) {
        int ans = 0;
        while (x) {
            ans += x / 5;
            x /= 5;
        }
        return ans;
    }
    long long f(int k) {
        long long l = 0, r = 5LL * k ;
        while (l <= r) {
            long long mid = (r - l) / 2 + l;
            if (getZeroNum(mid) < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r + 1;
    } 
public:
    int preimageSizeFZF(int k) {
        return f(k + 1) - f(k);
    }
};
// @lc code=end


