/*
 * @lc app=leetcode id=825 lang=cpp
 *
 * [825] Friends Of Appropriate Ages
 *
 * https://leetcode.com/problems/friends-of-appropriate-ages/description/
 *
 * algorithms
 * Medium (46.70%)
 * Likes:    683
 * Dislikes: 1177
 * Total Accepted:    78.2K
 * Total Submissions: 167K
 * Testcase Example:  '[16,16]'
 *
 * There are n persons on a social media website. You are given an integer
 * array ages where ages[i] is the age of the i^th person.
 * 
 * A Person x will not send a friend request to a person y (x != y) if any of
 * the following conditions is true:
 * 
 * 
 * age[y] <= 0.5 * age[x] + 7
 * age[y] > age[x]
 * age[y] > 100 && age[x] < 100
 * 
 * 
 * Otherwise, x will send a friend request to y.
 * 
 * Note that if x sends a request to y, y will not necessarily send a request
 * to x. Also, a person will not send a friend request to themself.
 * 
 * Return the total number of friend requests made.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ages = [16,16]
 * Output: 2
 * Explanation: 2 people friend request each other.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ages = [16,17,18]
 * Output: 2
 * Explanation: Friend requests are made 17 -> 16, 18 -> 17.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ages = [20,30,100,110,120]
 * Output: 3
 * Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 ->
 * 100.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == ages.length
 * 1 <= n <= 2 * 10^4
 * 1 <= ages[i] <= 120
 * 
 * 
 */

// @lc code=start
// class Solution {
// public:
//     int numFriendRequests(vector<int>& ages) {
        
//         long long  res = 0;
//         for(long long  i = 0; i < ages.size(); i++)
//         {
//             for(long long  j = 0; j < ages.size(); j++)
//             {
//                 if(i == j)
//                     continue;
//                 if(ages[j] <= 0.5 * ages[i] + 7)
//                     continue;
//                 if(ages[j] > ages[i])
//                     continue;
//                 if(ages[j] > 100 && ages[i] < 100)
//                     continue;
//                 res++;
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    //     int numFriendRequests(vector<int>& ages) {
    //     unordered_map<int, int> count;
    //     for (int &age : ages)
    //         count[age]++;
    //     int res = 0;
    //     for (auto &a : count)
    //         for (auto &b : count)
    //             if (request(a.first, b.first))
    //                 res += a.second * (b.second - (a.first == b.first ? 1 : 0));
    //     return res;
    // }

    // bool request(int a, int b) {
    //     return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    // }
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        for (int age : ages) count[age]++;

        int res = 0;
        for (int ageA = 0; ageA <= 120; ageA++) {
            int countA = count[ageA];
            for (int ageB = 0; ageB <= 120; ageB++) {
                int countB = count[ageB];
                if (ageB <= 0.5 * ageA + 7) continue;
                if (ageB > ageA) continue;
                if (ageB > 100 && ageA < 100) continue;
                res += countA * countB;
                if (ageA == ageB) res -= countA; 
            }
        }
        return res;
    }
};


// @lc code=end

