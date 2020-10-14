/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

/****************************************************
* 
* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
* 
* A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters. 
* 
* Example 1:
* 
* Input: digits = "23"
* Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
* Example 2:
* 
* Input: digits = ""
* Output: []
* Example 3:
* 
* Input: digits = "2"
* Output: ["a","b","c"]
*  
* 
* Constraints:
* 
* 0 <= digits.length <= 4
* digits[i] is a digit in the range ['2', '9'].
* 
****************************************************/

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> s1, s2;
        map<char,vector<string>> mp;
        mp['2']={"a","b","c"};
        mp['3']={"d","e","f"};
        mp['4']={"g","h","i"};
        mp['5']={"j","k","l"};
        mp['6']={"m","n","o"};
        mp['7']={"p","q","r","s"};
        mp['8']={"t","u","v"};
        mp['9']={"w","x","y","z"};
        for (auto item : digits) {
            int size = s1.size();
            auto &v = mp[item];
            for (auto &letter : v) {
                for (int i = 0; i < size; i++) {
                    s2.push_back(s1[i] + letter);
                }
                if (size == 0) s2.push_back(letter);
            }
            swap(s1, s2);
            s2.clear();
        }
        return s1;
    }
};
// @lc code=end


