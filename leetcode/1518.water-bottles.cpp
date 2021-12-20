/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int rem = 0;
        int emptyWaterBottle = 0;
        int ans = 0;
        while (numBottles)
        {
            ans += numBottles;
            emptyWaterBottle = numBottles+rem;
            numBottles = emptyWaterBottle/numExchange;
            rem = emptyWaterBottle%numExchange;  
        }
        return ans;
    }
};
// @lc code=end

