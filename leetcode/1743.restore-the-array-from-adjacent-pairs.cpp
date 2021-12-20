/*
 * @lc app=leetcode id=1743 lang=cpp
 *
 * [1743] Restore the Array From Adjacent Pairs
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for (int i = 0; i < adjacentPairs.size(); i++)
        {
            sort(adjacentPairs[i].begin(),adjacentPairs[i].end());
        }
        
        sort(adjacentPairs.begin(),adjacentPairs.end());
        vector<int> ans;
        int last = 0;
        for (int i = 0; i < adjacentPairs.size(); i++)
        {
            cout<<adjacentPairs[i][0]<<" "<<adjacentPairs[i][1]<<endl;
            if(last!=adjacentPairs[i][0]){
                ans.push_back(adjacentPairs[i][0]);
            }
            ans.push_back(adjacentPairs[i][1]);
            last = adjacentPairs[i][1];
        }
        return ans;
    }
};
// @lc code=end

