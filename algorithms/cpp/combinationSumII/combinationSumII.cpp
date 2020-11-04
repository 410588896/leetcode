/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

/*******************************************
* 
* Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
* 
* Each number in candidates may only be used once in the combination.
* 
* Note: The solution set must not contain duplicate combinations.
* 
*  
* 
* Example 1:
* 
* Input: candidates = [10,1,2,7,6,1,5], target = 8
* Output: 
* [
* [1,1,6],
* [1,2,5],
* [1,7],
* [2,6]
* ]
* Example 2:
* 
* Input: candidates = [2,5,2,1,2], target = 5
* Output: 
* [
* [1,2,2],
* [5]
* ]
*  
* 
* Constraints:
* 
* 1 <= candidates.length <= 100
* 1 <= candidates[i] <= 50
* 1 <= target <= 30
* 
*******************************************/

// @lc code=start
class Solution {
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;
    void dfs(int pos, int rest) {
        if (rest == 0) {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first) {
            return;
        }
        dfs(pos + 1, rest);
        int num = min(freq[pos].second, rest / freq[pos].first);
        for (int i = 1; i <= num; i++) {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 0; i < num; i++) {
            sequence.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (auto item : candidates) {
            if (freq.empty() || freq.back().first != item) {
                freq.push_back(pair<int, int>(item, 1));
            } else {
                ++(freq.back().second);
            }
        }
        dfs(0, target);
        return ans;
    }
};
// @lc code=end


