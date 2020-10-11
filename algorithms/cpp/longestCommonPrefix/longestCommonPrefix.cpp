/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

/******************************************************
* 
* Write a function to find the longest common prefix string amongst an array of strings.
* 
* If there is no common prefix, return an empty string "".
* 
*  
* 
* Example 1:
* 
* Input: strs = ["flower","flow","flight"]
* Output: "fl"
* Example 2:
* 
* Input: strs = ["dog","racecar","car"]
* Output: ""
* Explanation: There is no common prefix among the input strings.
*  
* 
* Constraints:
* 
* 0 <= strs.length <= 200
* 0 <= strs[i].length <= 200
* strs[i] consists of only lower-case English letters.
* 
******************************************************/

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.size() == 0) return res;
        for (int i = 0; i < strs[0].size(); i++) {
            int flag = 0;
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j].size() > i && strs[j][i] == strs[0][i]) continue;
                else {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) res += strs[0][i];
            else break;
        }
        return res;
    }
};
// @lc code=end


