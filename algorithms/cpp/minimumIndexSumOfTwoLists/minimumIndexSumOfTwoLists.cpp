/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> index;
        for (int i = 0; i < list1.size(); i++) {
            index[list1[i]] = i;
        }

        vector<string> ret;
        int indexSum = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            if (i > indexSum) return ret;
            if (index.count(list2[i]) > 0) {
                int j = index[list2[i]];
                if (i + j < indexSum) {
                    ret.clear();
                    ret.push_back(list2[i]);
                    indexSum = i + j;
                } else if (i + j == indexSum) {
                    ret.push_back(list2[i]);
                }
            }
        }
        return ret;
    }
};
