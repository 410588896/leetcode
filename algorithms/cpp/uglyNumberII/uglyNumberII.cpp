/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

/**********************************
* 
* Write a program to find the n-th ugly number.
* 
* Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
* 
* Example:
* 
* Input: n = 10
* Output: 12
* Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
* Note:  
* 
* 1 is typically treated as an ugly number.
* n does not exceed 1690.
* 
**********************************/

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> nums = vector<int>(n, 1);
        for (int i = 1; i < n; i++) {
            int ugly = min(nums[i2] * 2, min(nums[i3] * 3, nums[i5] * 5));
            nums[i] = ugly;
            if (nums[i2] * 2 == ugly) {
                i2++;
            } 
            if (nums[i3] * 3 == ugly) {
                i3++;
            } 
            if (nums[i5] * 5 == ugly) {
                i5++;
            }
        }
        return nums[n - 1];
    }
};
// @lc code=end


