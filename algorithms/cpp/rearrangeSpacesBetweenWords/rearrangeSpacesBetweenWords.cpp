/*
 * @lc app=leetcode.cn id=1592 lang=cpp
 *
 * [1592] 重新排列单词间的空格
 */

// @lc code=start
class Solution {
private:
vector<string_view> split(const string_view &str, char trim) {
    int n = str.size();
    vector<string_view> res;
    int pos = 0;
    while (pos < n) {
        while(pos < n && str[pos] == trim) {
            pos++;
        }
        if (pos < n) {
            int curr = pos;
            while(pos < n && str[pos] != trim) {
                pos++;
            }
            res.emplace_back(str.substr(curr, pos - curr));
        }
    }
    return res;
}
public:
    string reorderSpaces(string text) {
        int length = text.size();
        vector<string_view> words = split(text, ' ');
        int cntSpace = length;
        int wordCount = 0;
        for (auto &word : words) {
            if (word.size() > 0) {
                cntSpace -= word.size();
                wordCount++;
            }
        }
        string res;
        if (words.size() == 1) {
            res.append(words[0]);
            for (int i = 0; i < cntSpace; i++) {
                res.push_back(' ');
            }
            return res;
        }
        int perSpace = cntSpace / (wordCount - 1);
        int restSpace = cntSpace % (wordCount - 1);
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() == 0) {
                continue;
            }
            if (res.size() > 0) {
                for (int j = 0; j < perSpace; j++) {
                    res.push_back(' ');
                }
            }
            res.append(words[i]);
        }
        for (int i = 0; i < restSpace; i++) {
            res.push_back(' ');
        }
        return res;
    }
};
// @lc code=end


