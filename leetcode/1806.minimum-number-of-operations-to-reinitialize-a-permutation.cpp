/*
 * @lc app=leetcode id=1806 lang=cpp
 *
 * [1806] Minimum Number of Operations to Reinitialize a Permutation
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void operation(vector<int>& v){
        int n = v.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if(i%2==0) ans[i] = v[i/2];
            else ans[i] = v[n/2 + (i-1)/2];
        }
        v = ans;
        
    }
    int reinitializePermutation(int n) {
        vector<int> arr;
        for (int i = 0; i < n; i++) arr.push_back(i);
        vector<int> perm = arr;
        operation(perm);
        int ops = 1;
        while(perm!=arr){
            operation(perm);
            ops++;
        }
        return ops;
    }
};
// @lc code=end

