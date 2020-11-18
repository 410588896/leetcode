/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

/***************************************************
* 
* Given an m x n matrix, return all elements of the matrix in spiral order.
* 
*  
* 
* Example 1:
* 
* 
* Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
* Output: [1,2,3,6,9,8,7,4,5]
* Example 2:
* 
* 
* Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
* Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*  
* 
* Constraints:
* 
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 10
* -100 <= matrix[i][j] <= 100
* 
***************************************************/

// @lc code=start
class Solution {
private:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return res;
        }
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        int row = 0, column = 0, total = rows * columns;
        int directionIndex = 0;
        for (int i = 0; i < total; i++) {
            res.push_back(matrix[row][column]);
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0];
            int nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextColumn < 0 || nextRow >= rows || nextColumn >= columns || visited[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return res;
    }
};
// @lc code=end


