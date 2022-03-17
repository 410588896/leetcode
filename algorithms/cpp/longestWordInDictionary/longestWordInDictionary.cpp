/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            if (a.size() != b.size()) {
                return a.size() < b.size();
            } else {
                return a > b;
            }
        });
        unordered_set<string> cnt;
        cnt.insert("");
        string res;
        for (auto & word : words) {
            if (cnt.count(word.substr(0, word.size() - 1))) {
                res = word;
                cnt.insert(word);
            }
        }
        return res;
    }
};
