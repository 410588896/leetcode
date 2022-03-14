/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int elem1 = 0, elem2 = 0;
        int vote1 = 0, vote2 = 0;
        for (auto &num : nums) {
            if (vote1 > 0 && num == elem1) {
                vote1++;
            } else if (vote2 > 0 && num == elem2) {
                vote2++;
            } else if (vote1 == 0) {
                elem1 = num;
                vote1++;
            } else if (vote2 == 0) {
                elem2 = num;
                vote2++;
            } else {
                vote1--;
                vote2--;
            }
        }
        int cnt1 = 0, cnt2 = 0;
        for (auto &num : nums) {
            if (elem1 == num) {
                cnt1 ++;
            } else if (elem2 == num) {
                cnt2++;
            }
        }
        if (vote1 > 0 && cnt1 > nums.size() / 3) {
            res.push_back(elem1);
        }
        if (vote2 > 0 && cnt2 > nums.size() / 3) {
            res.push_back(elem2);
        }
        return res;
    }
};
