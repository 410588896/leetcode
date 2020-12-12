/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

/*****************************************
* 
* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
* 
*  
* 
* 
* Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
* 
*  
* 
* 
* The largest rectangle is shown in the shaded area, which has area = 10 unit.
* 
*  
* 
* Example:
* 
* Input: [2,1,5,6,2,3]
* Output: 10
* 
*****************************************/

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        vector<int> left(n), right(n);
        stack<int> monoStack;
        for (int i = 0; i < n; i++) {
            while (!monoStack.empty() && heights[monoStack.top()] >= heights[i]) {
                monoStack.pop();
            }
            left[i] = (monoStack.empty() == true ? -1 : monoStack.top());
            monoStack.push(i);
        }
        monoStack = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!monoStack.empty() && heights[monoStack.top()] >= heights[i]) {
                monoStack.pop();
            }
            right[i] = (monoStack.empty() == true ? n : monoStack.top());
            monoStack.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
    }
};
// @lc code=end


