/*
 * @lc app=leetcode id=1663 lang=cpp
 *
 * [1663] Smallest String With A Given Numeric Value
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        while(n){
            if(k-n+1>=26) {
                ans.push_back('z');
                k -= 26;
            }
            else{
                ans.push_back('a'-1+k-n+1);
                k = n-1;
            }
            n--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

