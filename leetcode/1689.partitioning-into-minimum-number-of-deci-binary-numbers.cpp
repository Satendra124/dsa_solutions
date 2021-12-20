/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minPartitions(string n) {
        char ans = *max_element(n.begin(),n.end());
        return ans-'0';
    }
};
// @lc code=end

