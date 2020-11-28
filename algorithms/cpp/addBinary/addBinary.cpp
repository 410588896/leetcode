/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

/**************************************
* 
* Given two binary strings a and b, return their sum as a binary string.
* 
*  
* 
* Example 1:
* 
* Input: a = "11", b = "1"
* Output: "100"
* Example 2:
* 
* Input: a = "1010", b = "1011"
* Output: "10101"
*  
* 
* Constraints:
* 
* 1 <= a.length, b.length <= 104
* a and b consist only of '0' or '1' characters.
* Each string does not contain leading zeros except for the zero itself.
* 
**************************************/

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() == 0) return b;
        if (b.size() == 0) return a;
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.size(), b.size());
        int anum = a.size(), bnum = b.size();
        int carry = 0;
        for (int i = 0; i < n; i++) {
            carry += i < anum ? a[i] == '1' : 0;
            carry += i < bnum ? b[i] == '1' : 0;
            res.push_back(carry % 2 ? '1' : '0');
            carry /= 2;
        }
        if (carry) {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end


