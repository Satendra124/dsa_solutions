/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        int n = g.size();
        int m = s.size();
        int i = 0,j=0;
        int ans = 0;
        while (i<n&&j<m)
        {
            if(g[i]<=s[j]){
                i++;
                j++;
                ans++;
            }else{
                i++;
            }
        }
        return ans;
        
    }
};
// @lc code=end

