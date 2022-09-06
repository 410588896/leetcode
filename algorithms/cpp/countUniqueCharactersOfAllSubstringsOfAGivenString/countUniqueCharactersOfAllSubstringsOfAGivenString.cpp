/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
class Solution {
private:
    unordered_map<char, vector<int>> dict;
public:
    int uniqueLetterString(string s) {
        for (int i = 0; i < s.size(); i++) {
            dict[s[i]].push_back(i);
        }
        int res = 0;
        for (auto &&[_, arr] : dict) {
            arr.insert(arr.begin(), -1);
            arr.push_back(s.size());
            for (int i = 1; i < arr.size() - 1; i++) {
                res += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }
        return res;
    }
};
// @lc code=end


