/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

/**********************************************
* 
* Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".
* 
* Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.
* 
*  
* 
* Example 1:
* 
* Input: s = "ADOBECODEBANC", t = "ABC"
* Output: "BANC"
* Example 2:
* 
* Input: s = "a", t = "a"
* Output: "a"
*  
* 
* Constraints:
* 
* 1 <= s.length, t.length <= 105
* s and t consist of English letters.
* 
**********************************************/

// @lc code=start
class Solution {
private:
    unordered_map<char, int> ori, cnt;
    bool check() {
        for (const auto & item : ori) {
            if (cnt[item.first] < item.second) {
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        for (auto item : t) {
            ++ori[item];
        }    
        int l = 0, r = -1;
        int resL = -1, len = INT_MAX;
        int n = s.size();
        while (r < n) {
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    resL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                l++;
            }
        }
        return resL == -1 ? string() : s.substr(resL, len);
    }
};
// @lc code=end


