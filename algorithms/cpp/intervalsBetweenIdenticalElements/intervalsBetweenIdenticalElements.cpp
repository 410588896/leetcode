/*
 * @lc app=leetcode.cn id=2121 lang=cpp
 *
 * [2121] 相同元素的间隔之和
 */

// @lc code=start
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
       int n = arr.size();
       vector<long long> res(n, 0);
       unordered_map<int, int> cnt;
       unordered_map<int, long long> total;
       for (int i = 0; i < n; i++) {
           if (cnt.count(arr[i]) != 0) {
               res[i] += (long long)i * cnt[arr[i]] - total[arr[i]];
           }
           total[arr[i]] += i;
           ++cnt[arr[i]];
        }
        total.clear();
        cnt.clear();
        for (int i = n - 1; i >= 0; i--) {
            if (cnt.count(arr[i]) != 0) {
                res[i] += total[arr[i]] - (long long)i * cnt[arr[i]];
            }
            total[arr[i]] += i;
            ++cnt[arr[i]];
        }
        return res;
    }
};
