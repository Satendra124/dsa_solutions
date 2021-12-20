/*
 * @lc app=leetcode id=1247 lang=cpp
 *
 * [1247] Minimum Swaps to Make Strings Equal
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length();
        int x = 0;
        int y = 0;
        for (int i = 0; i < n; i++)
        {
            if(s1[i]!=s2[i]){
                if(s1[i]=='x') x++;
                else y++;
            }
        }
        int ops = x/2 + y/2;
        x = x%2;
        y = y%2;
        if(x==y) return ops+x+y;
        else return -1;
    }
};
// @lc code=end

