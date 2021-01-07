/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

/***********************************
* 
* Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
* 
* A region is captured by flipping all 'O's into 'X's in that surrounded region.
* 
* Example:
* 
* X X X X
* X O O X
* X X O X
* X O X X
* After running your function, the board should be:
* 
* X X X X
* X X X X
* X X X X
* X O X X
* Explanation:
* 
* Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*
***********************************/

// @lc code=start
class Solution {
private:
    int n, m;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') return;
        board[x][y] = 'A';
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) return;
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
        return;
    }
};
// @lc code=end


