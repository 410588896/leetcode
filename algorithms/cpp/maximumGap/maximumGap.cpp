/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

/************************************
* 
* Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
* 
* Return 0 if the array contains less than 2 elements.
* 
* Example 1:
* 
* Input: [3,6,9,1]
* Output: 3
* Explanation: The sorted form of the array is [1,3,6,9], either
*              (3,6) or (6,9) has the maximum difference 3.
* Example 2:
* 
* Input: [10]
* Output: 0
* Explanation: The array contains less than 2 elements, therefore return 0.
* Note:
* 
* You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
* Try to solve it in linear time/space.
* 
************************************/

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        int d = max(1, (maxVal - minVal) / (n - 1));
        int bucketSize = (maxVal - minVal) / d + 1;
        vector<pair<int, int> > bucket(bucketSize, {-1, -1});
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - minVal) / d;
            if (bucket[idx].first == -1) {
                bucket[idx].first = bucket[idx].second = nums[i];
            } else {
                bucket[idx].first = min(bucket[idx].first, nums[i]);
                bucket[idx].second = max(bucket[idx].second, nums[i]);
            }
        }
        int ret = 0, prev = -1;
        for (int i = 0; i < bucketSize; i++) {
            if (bucket[i].first == -1) continue;
            if (prev != -1) {
                ret = max(ret, bucket[i].first - bucket[prev].second);
            }
            prev = i;
        }
        return ret;
    }
};
// @lc code=end


