/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegrees(n, 0); 
        for (vector<int> edge : edges) {
            inDegrees[edge[1]]++;
        }
        vector<int> ans;
        for (int i = 0; i < inDegrees.size(); ++i) {
            if (inDegrees[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    
    }
};
// @lc code=end

