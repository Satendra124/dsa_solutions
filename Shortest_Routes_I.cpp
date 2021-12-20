#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    bool visited[n+1];
    ll distance[n+1];
    distance[1] = 0;
    visited[1] =false;
    for (int i = 2; i < n+1; i++)
    {
        distance[i] = LONG_LONG_MAX;
        visited[i] = false;
    }
    
    map<int,vector<pair<int,int>>> graph;
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    priority_queue<pair<ll,int>> q;
    q.push({0,1});
    while (!q.empty())
    {
        int cur = q.top().second;q.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        for(pair<int,int> a:graph[cur]){
            ll next = a.first,w = a.second;
            if(distance[next]>distance[cur]+w){
                distance[next] = distance[cur]+w;
                q.push({-distance[next],next});
            }
            
        }   
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<distance[i]<<" ";
    }
    
    return 0;
}