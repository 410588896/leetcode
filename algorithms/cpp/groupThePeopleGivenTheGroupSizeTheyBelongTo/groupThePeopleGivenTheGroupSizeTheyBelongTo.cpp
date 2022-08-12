/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> dict;
        for (int i = 0; i < groupSizes.size(); i++) {
            dict[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for (auto &[size, people] : dict) {
            int i = 0;
            while (i < people.size()) {
                vector<int> tmp;
                int j = 0;
                while (j < size) {
                    tmp.push_back(people[i + j]);
                    j++;
                }
                i += j;
                res.push_back(tmp);
            }
        }
        return res;
    }
};
// @lc code=end


