/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> pointers(m, 1);
        vector<long> nums(m, 1);
        vector<long> dp(n + 1);
        dp[1] = 1;
        for (int i = 0; i < m; i++) {
            nums[i] = primes[i];
        }
        for (int i = 2; i <= n; i++) {
            long minNum = INT_MAX;
            int cur = 0;
            for (int j = 0; j < m; j++) {
                minNum = min(minNum, nums[j]);
            }
            dp[i] = minNum;
            for (int j = 0; j < m; j++) {
                if (nums[j] == minNum) {
                    pointers[j]++;
                    nums[j] = dp[pointers[j]] * primes[j];
                }
            }
        }
        return dp[n];
    }
};
