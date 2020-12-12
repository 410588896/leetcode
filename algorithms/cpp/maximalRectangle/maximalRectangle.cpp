/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
*/

/**********************************
* 
* Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
* 
*  
* 
* Example 1:
* 
* 
* Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
* Output: 6
* Explanation: The maximal rectangle is shown in the above picture.
* Example 2:
* 
* Input: matrix = []
* Output: 0
* Example 3:
* 
* Input: matrix = [["0"]]
* Output: 0
* Example 4:
* 
* Input: matrix = [["1"]]
* Output: 1
* Example 5:
* 
* Input: matrix = [["0","0"]]
* Output: 0
*  
* 
* Constraints:
* 
* rows == matrix.length
* cols == matrix.length
* 0 <= row, cols <= 200
* matrix[i][j] is '0' or '1'.
* 
**********************************/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m);
        vector<int> left(m);
        vector<int> right(m, m);
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int curLeft = 0, curRight = m;
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                }
                else {
                    right[j] = m;
                    curRight = j;
                }
            }
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                    left[j] = max(left[j], curLeft);
                    maxArea = max(maxArea, height[j] * (right[j] - left[j]));
                }
                else {
                    height[j] = 0;
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }
        }
        return maxArea;
    }
};

