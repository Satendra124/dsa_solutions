#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int n,m;
map<int,vector<int>> graph;
int last[100001];
bool visited[100001];
int main()
{
    fast;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<pair<int,int>> q;
    q.push({1,-1});
    bool ans = false;
    while (!q.empty()&&!ans)
    {
        int cur = q.front().first;
        int lasts = q.front().second;
        q.pop();
        if(cur==n) ans = true;
        if(visited[cur]) continue;
        last[cur] = lasts;
        visited[cur] = true;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            if(lasts!=graph[cur][i]) q.push({graph[cur][i],cur});
        }
    }
    // we need to trace the path
    if(ans){
        int cur = n;
        vector<int> path;
        while(cur!=-1){
            path.push_back(cur);
            cur = last[cur];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for (int i = 0; i < path.size(); i++)
        {
            cout<<path[i]<<" ";
        }
        
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}