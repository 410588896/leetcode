/*
 * @lc app=leetcode.cn id=1833 lang=cpp
 *
 * [1833] 雪糕的最大数量
 */

// @lc code=start
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ret = 0;
        for (auto cost : costs) {
            if (coins >= cost) {
                ret ++;
                coins -= cost;
            } else {
                break;
            }
        }
        return ret;
    }
};
// @lc code=end


