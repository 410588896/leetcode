/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

/*********************************************
* 
* Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
* 
*  
* 
* Example 1:
* 
* Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
* Output: [[1,6],[8,10],[15,18]]
* Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
* Example 2:
* 
* Input: intervals = [[1,4],[4,5]]
* Output: [[1,5]]
* Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*  
* 
* Constraints:
* 
* 1 <= intervals.length <= 104
* intervals[i].length == 2
* 0 <= starti <= endi <= 104
* 
*********************************************/

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 0) return {};
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || L > merged.back()[1]) {
                merged.push_back({L, R});
            } else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
// @lc code=end


