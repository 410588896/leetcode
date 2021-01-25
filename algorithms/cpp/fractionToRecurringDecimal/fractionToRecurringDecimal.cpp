/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

/*****************************************
* 
* Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
* 
* If the fractional part is repeating, enclose the repeating part in parentheses.
* 
* If multiple answers are possible, return any of them.
* 
* It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
* 
*  
* 
* Example 1:
* 
* Input: numerator = 1, denominator = 2
* Output: "0.5"
* Example 2:
* 
* Input: numerator = 2, denominator = 1
* Output: "2"
* Example 3:
* 
* Input: numerator = 2, denominator = 3
* Output: "0.(6)"
* Example 4:
* 
* Input: numerator = 4, denominator = 333
* Output: "0.(012)"
* Example 5:
* 
* Input: numerator = 1, denominator = 5
* Output: "0.2"
*  
* 
* Constraints:
* 
* -231 <= numerator, denominator <= 231 - 1
* denominator != 0
* 
*****************************************/

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "";
        if (numerator == 0) return "0";
        string res;
        long long num = static_cast<long long>(numerator);
        long long denom = static_cast<long long>(denominator);
        if ((num > 0) ^ (denom > 0)) res.push_back('-');
        num = llabs(num);
        denom = llabs(denom);
        res.append(to_string(num/denom));
        
        num %= denom;
        if (num == 0) return res;
        res.push_back('.');
        int idx = res.size() - 1;
        unordered_map<int, int> record;
        while (num && record.count(num) == 0) {
            record[num] = ++idx;
            num *= 10;
            res += to_string(num / denom);
            num %= denom;
        }
        if (record.count(num) == 1) {
            res.insert(record[num], "(");
            res.push_back(')');
        }
        return res;
    }
};
// @lc code=end


