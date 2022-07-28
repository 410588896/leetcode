/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> dict;
        for (int i = 0; i < sortedArr.size(); i++) {
            if (!dict.count(sortedArr[i])) {
                dict[sortedArr[i]] = dict.size() + 1;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = dict[arr[i]];
        }
        return arr;
    }
};
// @lc code=end


