/*
 * @lc app=leetcode.cn id=757 lang=cpp
 *
 * [757] 设置交集大小至少为2
 */

// @lc code=start
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
        int a = -1, b = -1, res = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] > b) {
                a = intervals[i][1] - 1;
                b = intervals[i][1];
                res += 2;
            } else if (intervals[i][0] > a) {
                a = b, b = intervals[i][1];
                res += 1;
            }
        }
        return res;
    }
};
// @lc code=end


