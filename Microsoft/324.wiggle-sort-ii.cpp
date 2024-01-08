/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 *
 * https://leetcode.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (33.95%)
 * Likes:    2990
 * Dislikes: 949
 * Total Accepted:    152.9K
 * Total Submissions: 449.7K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * Given an integer array nums, reorder it such that nums[0] < nums[1] >
 * nums[2] < nums[3]....
 * 
 * You may assume the input array always has a valid answer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,5,1,1,6,4]
 * Output: [1,6,1,5,1,4]
 * Explanation: [1,4,1,5,1,6] is also accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,3,2,2,3,1]
 * Output: [2,3,1,3,1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * 0 <= nums[i] <= 5000
 * It is guaranteed that there will be an answer for the given input nums.
 * 
 * 
 * 
 * Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
 */

// @lc code=start
class Solution {
public:
    // void wiggleSort(vector<int>& nums) {

    //     vector<int> tmp(nums);
    //     sort(tmp.begin(), tmp.end());
    //     int n = nums.size();
    //     int i = (n + 1) / 2 - 1;
    //     int j = n - 1;
    //     for (int k = 0; k < n; ++k) {
    //         if (k & 1) {
    //             nums[k] = tmp[j--];
    //         } else {
    //             nums[k] = tmp[i--];
    //         }        
    //     } 
    // }
    void wiggleSort(vector<int>& nums) 
    {
        int n = nums.size();

        if(n == 1)
            return;
        
        sort(nums.begin(), nums.end());

        vector<int> ans(n);
        int mid;

        if(n % 2)
            mid = (n / 2) + 1;
        else
            mid = n / 2;
  
        int i = 1;
        int j = n - 1;
        
        while(j > mid)
        {
            ans[i] = nums[j];
            i+= 2;
            j--;
        }

        i = 0;
        while(j >= 0)
        {
            ans[i] = nums[j];
            i+= 2;
            j--;
        }
    }
};
// @lc code=end

