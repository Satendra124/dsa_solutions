/*
 * @lc app=leetcode id=1433 lang=cpp
 *
 * [1433] Check If a String Can Break Another String
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool ans  = true;
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            if(s1[i]>s2[i]) {
                ans = false;
                break;
            }
        }
        if(ans) return ans;
        ans = true;
        for (int i = 0; i < n; i++)
        {
            if(s1[i]<s2[i]) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

