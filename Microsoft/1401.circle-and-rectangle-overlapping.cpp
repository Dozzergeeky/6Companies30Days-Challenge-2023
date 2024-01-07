/*
 * @lc app=leetcode id=1401 lang=cpp
 *
 * [1401] Circle and Rectangle Overlapping
 *
 * https://leetcode.com/problems/circle-and-rectangle-overlapping/description/
 *
 * algorithms
 * Medium (45.19%)
 * Likes:    333
 * Dislikes: 77
 * Total Accepted:    14.8K
 * Total Submissions: 32.6K
 * Testcase Example:  '1\n0\n0\n1\n-1\n3\n1'
 *
 * You are given a circle represented as (radius, xCenter, yCenter) and an
 * axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are
 * the coordinates of the bottom-left corner, and (x2, y2) are the coordinates
 * of the top-right corner of the rectangle.
 * 
 * Return true if the circle and rectangle are overlapped otherwise return
 * false. In other words, check if there is any point (xi, yi) that belongs to
 * the circle and the rectangle at the same time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
 * Output: true
 * Explanation: Circle and rectangle share the point (1,0).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 =
 * -1
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= radius <= 2000
 * -10^4 <= xCenter, yCenter <= 10^4
 * -10^4 <= x1 < x2 <= 10^4
 * -10^4 <= y1 < y2 <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
       
            int x = xCenter;
            int y = yCenter;
            if (xCenter < x1) {
                x = x1;
            } else if (xCenter > x2) {
                x = x2;
            }
            if (yCenter < y1) {
                y = y1;
            } else if (yCenter > y2) {
                y = y2;
            }
            int dist = (xCenter - x) * (xCenter - x) + (yCenter - y) * (yCenter - y);
            return dist <= radius * radius;


    }
};
// @lc code=end

