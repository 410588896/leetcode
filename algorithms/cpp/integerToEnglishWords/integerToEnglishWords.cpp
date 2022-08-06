/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution {
private:
    vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        string res;
        if (num == 0) return "Zero";
        for (int i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000) {
            int curNum = num / unit;
            if (curNum != 0) {
                num -= curNum * unit;
                res += toEnglish(curNum) + thousands[i] + " ";
            }
        }
        while (res.back() == ' ') {
            res.pop_back();
        }
        return res;
    }

    string toEnglish(int num) {
        string ret;
        int hundred = num / 100;
        num %= 100;
        if (hundred != 0) {
            ret += singles[hundred] + " Hundred ";
        }
        int ten = num / 10;
        if (ten >= 2) {
            ret += tens[ten] + " ";
            num %= 10;
        }
        if (num > 0 && num < 10) {
            ret += singles[num] + " ";
        } else if (num >= 10) {
            ret += teens[num - 10] + " "; 
        }
        return ret;
    }
};
// @lc code=end


