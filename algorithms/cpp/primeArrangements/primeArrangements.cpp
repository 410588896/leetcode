/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 */

// @lc code=start
class Solution {
private:
    const long MOD = 1e9 + 7;
    bool isPrime(int x) {
        if (x == 1) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    long numCount(int x) {
        long res = 1;
        for (int i = 1; i <= x; i++) {
            res *= i;
            res %= MOD;
        }
        return res;
    }
public:
    int numPrimeArrangements(int n) {
        int primeCount = 0;
        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) primeCount++;
        }
        return int(numCount(primeCount) * numCount(n - primeCount) % MOD);
    }
};
// @lc code=end


