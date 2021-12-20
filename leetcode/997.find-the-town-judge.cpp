/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int,int> tpoints;
        for (int i = 0; i < trust.size(); i++)
        {
            tpoints[trust[i][0]]--;
            tpoints[trust[i][1]]++;
        }
        for (int i = 1; i <= N; i++)
        {
            //cout<<i<<" "<<tpoints[i]<<endl;
            if(tpoints[i]==N-1) return i;
        }
        return -1;
        
    }
};
// @lc code=end

