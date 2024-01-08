/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 *
 * https://leetcode.com/problems/count-number-of-nice-subarrays/description/
 *
 * algorithms
 * Medium (63.99%)
 * Likes:    3607
 * Dislikes: 77
 * Total Accepted:    109.5K
 * Total Submissions: 171K
 * Testcase Example:  '[1,1,2,1,1]\n3'
 *
 * Given an array of integers nums and an integer k. A continuous subarray is
 * called nice if there are k odd numbers on it.
 * 
 * Return the number of nice sub-arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2,1,1], k = 3
 * Output: 2
 * Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and
 * [1,2,1,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,4,6], k = 1
 * Output: 0
 * Explanation: There is no odd numbers in the array.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * Output: 16
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0, count = 0;
    vector<int> prefix(n + 1, 0);
    prefix[0] = 1;

    for (int i = 0; i < n; i++) {
        count += nums[i] % 2;
        prefix[count]++;
        if (count >= k) {
            ans += prefix[count - k];
        }
    }
    return ans;
    }
   
};
// @lc code=end

