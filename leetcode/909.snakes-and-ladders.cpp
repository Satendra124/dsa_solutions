// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem909.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int,int>> q; // curPos, step to get there
        int n = board.size();   
        vector<bool> visited(n*n+1,false);
        q.push({1,0});
        while(!q.empty()){
            int curPos = q.front().first;
            int st = q.front().second;
            q.pop();
            if(curPos>n*n) continue;
            if(visited[curPos]) continue;
            if(curPos==n*n) return st;
            visited[curPos] = true;
            int x =n - (curPos/n) - 1;
            if(curPos%n==0) x++;
            int y;
            if((n-1-x)%2==0){
                //odd starts from left
                y = curPos%n-1;
            }else y =n - curPos%n; 
            if(y<0) y+= n;
            cout<<curPos<<" "<<x<<" "<<y<<endl;
            if(board[x][y]==-1){
                for(int i=1;i<=6;i++) q.push({curPos+i,st+1});
            }else{
                q.push({board[x][y],st+1});
            }
        }
        return -1;
    }
};
// @lc code=end

