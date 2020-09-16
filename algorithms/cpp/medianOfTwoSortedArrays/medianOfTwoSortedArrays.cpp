/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

/********************************************************
* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
* 
* Follow up: The overall run time complexity should be O(log (m+n)).
* 
*  
* 
* Example 1:
* 
* Input: nums1 = [1,3], nums2 = [2]
* Output: 2.00000
* Explanation: merged array = [1,2,3] and median is 2.
* Example 2:
* 
* Input: nums1 = [1,2], nums2 = [3,4]
* Output: 2.50000
* Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
* Example 3:
* 
* Input: nums1 = [0,0], nums2 = [0,0]
* Output: 0.00000
* Example 4:
* 
* Input: nums1 = [], nums2 = [1]
* Output: 1.00000
* Example 5:
* 
* Input: nums1 = [2], nums2 = []
* Output: 2.00000
*  
* 
* Constraints:
* 
* nums1.length == m
* nums2.length == n
* 0 <= m <= 1000
* 0 <= n <= 1000
* 1 <= m + n <= 2000
* -106 <= nums1[i], nums2[i] <= 106
*
*****************************************************************/

// @lc code=start
class Solution {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true) {
            if (index1 == m) {
                return nums2[index2 + k - 1];
            } 
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            if (nums1[newIndex1] <= nums2[newIndex2]) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            } else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        } else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};
// @lc code=end

