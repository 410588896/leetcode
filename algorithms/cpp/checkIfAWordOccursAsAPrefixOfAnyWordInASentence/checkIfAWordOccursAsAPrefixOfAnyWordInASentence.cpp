/*
 * @lc app=leetcode.cn id=1455 lang=cpp
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

// @lc code=start
class Solution {
private:
    bool isPrefix(string &sentence, int start, int end, string &searchWord) {
        for (int i = 0; i < searchWord.size(); i++) {
            if (start + i >= end || sentence[start + i] != searchWord[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int start = 0, end = 0, index = 1;
        int n = sentence.size();
        while (start < n) {
            while (end < n && sentence[end] != ' ') {
                end ++;
            }
            if (isPrefix(sentence, start, end, searchWord)) {
                return index;
            }
            end++;
            start = end;
            index ++;
        }
        return -1;
    }
};
// @lc code=end


