/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (59.95%)
 * Likes:    3270
 * Dislikes: 120
 * Total Accepted:    173.4K
 * Total Submissions: 289.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of size n, return the minimum number of moves
 * required to make all array elements equal.
 * 
 * In one move, you can increment or decrement an element of the array by 1.
 * 
 * Test cases are designed so that the answer will fit in a 32-bit integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: 2
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,10,2,9]
 * Output: 16
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {

        // nth element
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += abs(nums[i] - nums[nums.size() / 2]);
        }
        return ans; 
    }
};
// @lc code=end

