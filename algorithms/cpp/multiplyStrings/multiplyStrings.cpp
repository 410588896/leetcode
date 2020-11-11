/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
*/

/***************************************
* 
* Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
* 
* Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
* 
*  
* 
* Example 1:
* 
* Input: num1 = "2", num2 = "3"
* Output: "6"
* Example 2:
* 
* Input: num1 = "123", num2 = "456"
* Output: "56088"
*  
* 
* Constraints:
* 
* 1 <= num1.length, num2.length <= 200
* num1 and num2 consist of digits only.
* Both num1 and num2 do not contain any leading zero, except the number 0 itself.
* 
***************************************/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        auto ansArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10; 
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        string res;
        while (index < m + n) {
            res.push_back(ansArr[index] + '0');
            index++;
        }
        return res;
    }
};

 
