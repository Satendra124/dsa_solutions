/*
 * @lc app=leetcode id=1685 lang=cpp
 *
 * [1685] Sum of Absolute Differences in a Sorted Array
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int arr1[n-1];
        for(int i=0;i<n-1;i++){
            arr1[i] =nums[i+1] - nums[i] ;
        }
        int forwardtemp[n-1];
        int backwardtemp[n-1];
        for (int i = 0; i < n-1; i++)
        {
            forwardtemp[i] =arr1[i] * (n-1-i);
            backwardtemp[i] =arr1[i]*( i+1);
        }
        int forward[n-1];
        int backward[n-1];
        forward[n-2] = forwardtemp[n-2];
        backward[0] = backwardtemp[0];
        for(int i=n-3;i>=0;i--){
            forward[i] = forward[i+1] + forwardtemp[i];
        }
        for(int i=1;i<n-1;i++){
            backward[i] = backward[i-1] + backwardtemp[i];
        }
        // for (int i = 0; i < n-1; i++)
        // {
        //     cout<<forwardtemp[i]<<" ";
        // }
        // cout<<endl;
        // for (int i = 0; i < n-1; i++)
        // {
        //     cout<<backwardtemp[i]<<" ";
        // }
        // cout<<endl;
        vector<int> ans(n,0);
        ans[0] = forward[0];
        ans[n-1] = backward[n-2];
        for (int i = 1; i < n-1; i++)
        {
            ans[i] = forward[i] + backward[i-1];
        }
        return ans;
        
    }
};
// @lc code=end

