/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
class Solution {
private:
    int make(const char &c) {
        switch(c) {
            case ' ' : return 0;
            case '+' : return 1;
            case '-' : return 1;
            case '.' : return 3;
            case 'e' : return 4;
            default:
                if ('0' <= c && c <= '9') return 2;
                else return 5; 
        }
    }
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        vector<vector<int> > table({
                                       { 0, 1, 6, 2,-1,-1},
                                       {-1,-1, 6, 2,-1,-1},
                                       {-1,-1, 3,-1,-1,-1},
                                       { 8,-1, 3,-1, 4,-1},
                                       {-1, 7, 5,-1,-1,-1},
                                       { 8,-1, 5,-1,-1,-1},
                                       { 8,-1, 6, 3, 4,-1},
                                       {-1,-1, 5,-1,-1,-1},
                                       { 8,-1,-1,-1,-1,-1},
                                       });
        vector<bool> finals({0, 0, 0, 1, 0, 1, 1, 0, 1});
        int state = 0;
        for (auto elem : s) {
            state = table[state][make(elem)];
            if (state < 0) return false;
        }
        return finals[state];
    }
};
// @lc code=end


