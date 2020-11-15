/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

/*****************************************
* 
* Given an array of strings strs, group the anagrams together. You can return the answer in any order.
* 
* An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
* 
*  
* 
* Example 1:
* 
* Input: strs = ["eat","tea","tan","ate","nat","bat"]
* Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
* Example 2:
* 
* Input: strs = [""]
* Output: [[""]]
* Example 3:
* 
* Input: strs = ["a"]
* Output: [["a"]]
*  
* 
* Constraints:
* 
* 1 <= strs.length <= 104
* 0 <= strs[i].length <= 100
* strs[i] consists of lower-case English letters.
* 
*****************************************/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > dict;
        vector<vector<string>> res;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (dict.find(tmp) != dict.end()) {
                dict[tmp].push_back(strs[i]);
            } else {
                dict[tmp] = vector<string>{strs[i]};
            }
        }
        for (auto it : dict) {
            res.push_back(it.second);
        }
        return res;
    }
};


