/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

/*************************************

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.

*************************************/

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            if (left < right) {
                if (tolower(s[left]) == tolower(s[right])) {
                    left++, right--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end


