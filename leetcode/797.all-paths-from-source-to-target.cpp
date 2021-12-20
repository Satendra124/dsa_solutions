/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:

    vector<vector<int>> ans;
    void iter(vector<vector<int>>& graph,vector<int> curPath,int cur,int n){
        curPath.push_back(cur);
        //cout<<cur<<endl;
        if(cur==n){
            ans.push_back(curPath);
            return;
        }
        for (int i = 0; i < graph[cur].size(); i++)
        {
            iter(graph,curPath,graph[cur][i],n);
        }
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        iter(graph,vector<int>(),0,graph.size()-1);
        return ans;
    }
};
// @lc code=end

