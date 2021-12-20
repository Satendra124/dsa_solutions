#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
bool visited[501][501];
int s;
void dfs(int i,int j,vector<vector<char>>& maze){
    if(i==maze.size()||j==maze[0].size()||i<0||j<0) return;
    if(maze[i][j]=='#') return;
    if(visited[i][j]) return;
    visited[i][j] = true;
    if(s<=0) maze[i][j]='X';
    s--;
    dfs(i+1,j,maze);
    dfs(i,j+1,maze);
    dfs(i-1,j,maze);
    dfs(i,j-1,maze);
}

int main()
{
    fast;
    int n,m,k;
    cin>>n>>m>>k;
    s = 0;
    int si = 0,sj=0;
    vector<vector<char>> maze(n,vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='.') {
                s++;
                si = i;
                sj = j;
            }
        }
    }
    s = s-k;
    dfs(si,sj,maze);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<maze[i][j];
        }
        cout<<endl;
    }
    return 0;
}