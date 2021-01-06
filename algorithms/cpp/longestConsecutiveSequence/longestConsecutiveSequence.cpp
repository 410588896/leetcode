/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

/***************************************
* 
* Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
* 
* Follow up: Could you implement the O(n) solution? 
* 
*  
* 
* Example 1:
* 
* Input: nums = [100,4,200,1,3,2]
* Output: 4
* Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
* Example 2:
* 
* Input: nums = [0,3,7,2,5,8,4,6,0,1]
* Output: 9
*  
* 
* Constraints:
* 
* 0 <= nums.length <= 104
* -109 <= nums[i] <= 109
* 
***************************************/

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (auto num : nums) numSet.insert(num);
        int longestStreak = 0;
        for (auto num : numSet) {
            if (!numSet.count(num - 1)) {
                int curNum = num;
                int curLongest = 1;
                while (numSet.count(curNum + 1)) {
                    curNum += 1;
                    curLongest += 1;
                }
                longestStreak = max(longestStreak, curLongest);
            }
        }
        return longestStreak;
    }
};
// @lc code=end


