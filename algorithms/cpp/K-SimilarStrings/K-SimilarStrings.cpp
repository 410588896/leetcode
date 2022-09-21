/*
 * @lc app=leetcode.cn id=854 lang=cpp
 *
 * [854] 相似度为 K 的字符串
 */

// @lc code=start
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.size();
        queue<pair<string, int>> qu;
        unordered_set<string> visited;
        qu.emplace(s1, 0);
        visited.insert(s1);
        for (int step = 0; ; step++) {
            int sz = qu.size();
            for (int i = 0; i < sz; i++) {
                auto [cur, pos] = qu.front();
                qu.pop();
                if (cur == s2) return step;
                while(pos < n && cur[pos] == s2[pos]) {
                    pos++;
                }
                for (int j = pos + 1; j < n; j++) {
                    if (cur[j] != s2[j] && cur[j] == s2[pos]) {
                        swap(cur[j], cur[pos]);
                        if (!visited.count(cur)) {
                            qu.emplace(cur, pos + 1);
                            visited.insert(cur);
                        }
                        swap(cur[j], cur[pos]);
                    }
                }
            }
        }
    }
};
// @lc code=end


