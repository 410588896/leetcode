/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

/***************************************
* 
* Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
* 
* If target is not found in the array, return [-1, -1].
* 
* Follow up: Could you write an algorithm with O(log n) runtime complexity?
* 
*  
* 
* Example 1:
* 
* Input: nums = [5,7,7,8,8,10], target = 8
* Output: [3,4]
* Example 2:
* 
* Input: nums = [5,7,7,8,8,10], target = 6
* Output: [-1,-1]
* Example 3:
* 
* Input: nums = [], target = 0
* Output: [-1,-1]
*  
* 
* Constraints:
* 
* 0 <= nums.length <= 105
* -109 <= nums[i] <= 109
* nums is a non-decreasing array.
* -109 <= target <= 109
* 
***************************************/

// @lc code=start
class Solution {
private:
    int myLowerBound(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int mid, pos = 0;
        while (l < h) {
            mid = (h - l) / 2 + l;
            if (nums[mid] < target) {
                l = mid + 1;
                pos = l;
            } else {
                h = mid;
                pos = h;
            }
        }
        return pos;
    }
    int myUpperBound(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int mid, pos = 0;
        while (l < h) {
            mid = (h - l) / 2 + l;
            if (nums[mid] > target) {
                h = mid;
                pos = h;
            } else {
                l = mid + 1;
                pos = l;
            }
        }
        return pos;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if (nums.size() == 0) return res;
        int low = myLowerBound(nums, target);
        if (nums[low] != target) return res;
        int high = myUpperBound(nums, target);
        res[0] = low;
        res[1] = nums[high] == target ? high : high - 1;
        return res;
    }
};
// @lc code=end


