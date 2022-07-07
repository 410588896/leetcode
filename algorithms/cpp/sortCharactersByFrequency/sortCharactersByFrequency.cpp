/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        for (auto ch : s) {
            maxFreq = max(maxFreq, ++mp[ch]);
        }
        vector<string> buckets(maxFreq + 1);
        for (auto &[ch, num] : mp) {
            buckets[num].push_back(ch);
        }
        string ret;
        for (int i = maxFreq; i > 0 ; i--) {
            string bucket = buckets[i];
            for (auto ch : bucket) {
                for (int j = 0; j < i; j++) {
                    ret.push_back(ch);
                }
            }
        }
        return ret;
    }
};
// @lc code=end


