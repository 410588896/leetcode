/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

/*************************************
* 
* Given an m x n board and a word, find if the word exists in the grid.
* 
* The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
* 
*  
* 
* Example 1:
* 
* 
* Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
* Output: true
* Example 2:
* 
* 
* Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
* Output: true
* Example 3:
* 
* 
* Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
* Output: false
*  
* 
* Constraints:
* 
* m == board.length
* n = board[i].length
* 1 <= m, n <= 200
* 1 <= word.length <= 103
* board and word consists only of lowercase and uppercase English letters.
* 
***************************************/

// @lc code=start
class Solution {
private:
    bool check(vector<vector<char>>& board, vector<vector<bool>> &visited, int i, int j, string s, int k) {
        if (board[i][j] != s[k]) return false;
        else if (k == s.size() - 1) return true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        visited[i][j] = true;
        bool result = false;
        for (const auto &dir : directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >=0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    if(check(board, visited, newi, newj, s, k + 1)) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (check(board, visited, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end


