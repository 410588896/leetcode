/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

/************************************
* 
* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
* 
* Note:
* 
* The same word in the dictionary may be reused multiple times in the segmentation.
* You may assume the dictionary does not contain duplicate words.
* Example 1:
* 
* Input:
* s = "catsanddog"
* wordDict = ["cat", "cats", "and", "sand", "dog"]
* Output:
* [
*   "cats and dog",
*   "cat sand dog"
* ]
* Example 2:
* 
* Input:
* s = "pineapplepenapple"
* wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
* Output:
* [
*   "pine apple pen apple",
*   "pineapple pen apple",
*   "pine applepen apple"
* ]
* Explanation: Note that you are allowed to reuse a dictionary word.
* Example 3:
* 
* Input:
* s = "catsandog"
* wordDict = ["cats", "dog", "sand", "and", "cat"]
* Output:
* []
* 
************************************/

// @lc code=start
class Solution {
private:
    unordered_map<int, vector<string> > res;
    unordered_set<string> wordSet;
    void backtrack(const string &s, int index) {
        if (!res.count(index)) {
            if (index == s.size()) {
                res[index] = {""};
                return;
            }
            res[index] = {};
            for (int i = index + 1; i <= s.size(); i++) {
                string word = s.substr(index, i - index);
                if (wordSet.find(word) != wordSet.end()) {
                    backtrack(s, i);
                    for (const string &item : res[i]) {
                        res[index].push_back(item.empty() ? word : word + " " + item);
                    }
                }
            }
        }
        return;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return res[0];
    }
};
// @lc code=end


