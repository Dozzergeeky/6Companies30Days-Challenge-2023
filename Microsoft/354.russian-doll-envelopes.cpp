/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (37.22%)
 * Likes:    5772
 * Dislikes: 140
 * Total Accepted:    207.6K
 * Total Submissions: 558.1K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi]
 * represents the width and the height of an envelope.
 * 
 * One envelope can fit into another if and only if both the width and height
 * of one envelope are greater than the other envelope's width and height.
 * 
 * Return the maximum number of envelopes you can Russian doll (i.e., put one
 * inside the other).
 * 
 * Note: You cannot rotate an envelope.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: envelopes = [[1,1],[1,1],[1,1]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= envelopes.length <= 10^5
 * envelopes[i].length == 2
 * 1 <= wi, hi <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

       vector<int> dp;
         sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
              return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
         });
            for (auto& envelope : envelopes) {
                auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);
                if (it == dp.end()) dp.push_back(envelope[1]);
                else *it = envelope[1];
            }
            return dp.size(); 
    }
};
// @lc code=end

