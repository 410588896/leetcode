/*
 * @lc app=leetcode.cn id=564 lang=cpp
 *
 * [564] 寻找最近的回文数
 */

// @lc code=start
class Solution {
private:
    vector<long> getCandidates(const string& n) {
        int len = n.length();
        vector<long> candidates = {
            (long)pow(10, len - 1) - 1,
            (long)pow(10, len) + 1,
        };
        long prefixNum = stol(n.substr(0, (len + 1) / 2));
        for (int i : {prefixNum - 1, prefixNum, prefixNum + 1}) {
            string prefix = to_string(i);
            candidates.push_back(stol(prefix + string(prefix.rbegin() + (len & 1), prefix.rend())));
        }
        return candidates;
    }
public:
    string nearestPalindromic(string n) {
        long num = stol(n), res = -1;
        const vector<long> &candidates = getCandidates(n);
        for (auto &candidate : candidates) {
            if (candidate != num) {
                if (res == -1 || 
                    abs(candidate - num) < abs(res - num) ||
                    (abs(candidate - num) == abs(res - num) && candidate < res)) {
                    res = candidate;
                }  
            }
        }
        return to_string(res);
    }
};
