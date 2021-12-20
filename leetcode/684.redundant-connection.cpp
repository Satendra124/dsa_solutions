/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int,vector<int>> graph;
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        queue<int> q;
        map<int,bool> isVisited;
        q.push(edges[0][0]);
        vector<vector<int>> possibleAns;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < graph[cur].size(); i++)
            {
                if(isVisited[graph[cur][i]]) possibleAns.push_back({cur,graph[cur][i]});
                q.push(graph[cur][i]);
                isVisited[graph[cur][i]] = true;
            }
        }
        for (int i = 0; i < edges.size(); i++)
        {
            if(find(possibleAns.begin(),possibleAns.end(),edges[i])!=possibleAns.end()){
                return edges[i];
            }
        }
        
        return {-1};
    }
};
// @lc code=end

