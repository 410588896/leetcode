/*
 * @lc app=leetcode.cn id=636 lang=cpp
 *
 * [636] 函数的独占时间
 */

// @lc code=start
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int> > st;
        vector<int> res(n, 0);
        for (auto & log : logs) {
            int idx = 0, timestamp = 0;
            char type[10] = "\0";
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp);
            if (type[0] == 's') {
                if (!st.empty()) {
                    res[st.top().first] += timestamp - st.top().second;
                }
                st.push(make_pair(idx, timestamp));
            } else {
                auto t = st.top();
                st.pop();
                res[t.first] += timestamp - t.second + 1;
                if (!st.empty()) {
                    st.top().second = timestamp + 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end


