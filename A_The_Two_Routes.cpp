#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int bfs(vector<vector<int>> graph,int n){
    queue<pair<int,int>> q;
    q.push({1,0});
    bool visited[graph.size()+1];
    int ans = INT_MAX;
    memset(visited,false,sizeof(visited));
    while(!q.empty()){
        int cur = q.front().first;
        int t = q.front().second;
        q.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        if(cur==graph.size()-1) ans = min(ans,t);
        for (int i = 0; i < graph[cur].size(); i++)
        {
            if(graph[cur][i]==n) q.push({i,t+1});
        }

    }
    return ans;
}

int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1,vector<int>(n+1,2));
    //1 - rail 2 - road 0-none
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        graph[i][i] = 0;
        graph[0][i] = 0;
        graph[i][0] = 0;
    }
    int t1 = bfs(graph,1);
    int t2 = bfs(graph,2);
    int ans = max(t1,t2);
    if(ans==INT_MAX) ans = -1;
    cout<<ans<<endl;
    return 0;
}