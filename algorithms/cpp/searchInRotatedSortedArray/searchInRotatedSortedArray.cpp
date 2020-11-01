/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

/*********************************************
* 
* You are given an integer array nums sorted in ascending order, and an integer target.
* 
* Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
* 
* If target is found in the array return its index, otherwise, return -1.
* 
*  
* 
* Example 1:
* 
* Input: nums = [4,5,6,7,0,1,2], target = 0
* Output: 4
* Example 2:
* 
* Input: nums = [4,5,6,7,0,1,2], target = 3
* Output: -1
* Example 3:
* 
* Input: nums = [1], target = 0
* Output: -1
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 5000
* -10^4 <= nums[i] <= 10^4
* All values of nums are unique.
* nums is guranteed to be rotated at some pivot.
* -10^4 <= target <= 10^4
* 
*********************************************/

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end


