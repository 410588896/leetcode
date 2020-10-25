/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

/********************************************
* 
* You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.
* 
* You can return the answer in any order.
* 
*  
* 
* Example 1:
* 
* Input: s = "barfoothefoobarman", words = ["foo","bar"]
* Output: [0,9]
* Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
* The output order does not matter, returning [9,0] is fine too.
* Example 2:
* 
* Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
* Output: []
* Example 3:
* 
* Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
* Output: [6,9,12]
*  
* 
* Constraints:
* 
* 1 <= s.length <= 104
* s consists of lower-case English letters.
* 1 <= words.length <= 5000
* 1 <= words[i].length <= 30
* words[i] consists of lower-case English letters.
* 
********************************************/

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.size() == 0 || words.size() == 0) return res;
        unordered_map<string, int> m1;
        for (auto item : words) m1[item]++;
        int n = words.size();
        int m = words[0].size();
        for (int i = 0; i <= int(s.size()) - n * m; i++) {
            unordered_map<string, int> m2;
            int j = 0;
            for (j = 0; j < n; j++) {
                string item = s.substr(i + j * m, m);
                if (m1.find(item) == m1.end()) break;
                ++m2[item];
                if (m2[item] > m1[item]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end


