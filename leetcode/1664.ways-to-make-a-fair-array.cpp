/*
 * @lc app=leetcode id=1664 lang=cpp
 *
 * [1664] Ways to Make a Fair Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int front[n];
        int back[n];
        front[0] = nums[0];
        if(n>1)
        front[1] = nums[1];
        for (int i = 2; i < n; i++) front[i] =nums[i]+front[i-2];
        if(n-1>0)
        back[n-1] = nums[n-1];
        if(n-2>0)
        back[n-2] = nums[n-2];
        for (int i = n-3; i >=0; i--) back[i] =nums[i]+back[i+2];
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<front[i]<<" ";
        // }
        // cout<<endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<back[i]<<" ";
        // }
        // cout<<endl;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int s1=0,s2=0,s3=0,s4=0;
            if(i-2>=0) s1 += front[i-2];
            if(i-1>=0) s2 += front[i-1];
            if(i+1<n)  s3 += back[i+1];
            if(i+2<n)  s4 += back[i+2];
            //cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
            if(s1+s3==s2+s4) cnt++;
        }
        
        return cnt;
        
    }
};
// @lc code=end

