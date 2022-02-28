/*
 * @lc app=leetcode.cn id=1601 lang=cpp
 *
 * [1601] 最多可达成的换楼请求数目
 */

// @lc code=start
class Solution {
private:
    vector<int> delta;
    int cnt = 0, res = 0, n, zero;
public:
    void dfs(vector<vector<int>>& requests, int pos) {
        if (pos == requests.size()) {
            if (zero == n) res = max(res, cnt);
            return;
        } 
        // not choose
        dfs(requests, pos + 1);

        // choose
        int z = zero;
        cnt ++;
        int x = requests[pos][0];
        int y = requests[pos][1];
        zero -= delta[x] == 0;
        --delta[x];
        zero += delta[x] == 0;
        zero -= delta[y] == 0;
        ++delta[y];
        zero += delta[y] == 0;
        dfs(requests, pos + 1);
        zero = z;
        cnt --;
        ++delta[x];
        --delta[y];
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        delta.resize(n);
        zero = n;
        this->n = n;
        dfs(requests, 0);
        return this->res;
    }
};
