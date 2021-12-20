#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int n,m;
map<int,vector<int>> graph;
int ans[100001];
bool visited[100001];
bool ansValid = true;
void dfs(int cur,int last){
    //cout<<cur<<" "<<last<<endl;
    if(visited[cur]) {
        if(ans[cur]!=last) {
            ansValid = false;
        }
        return;
    }
    ans[cur] = last;
    visited[cur] = true;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        dfs(graph[cur][i],1 + !(last-1));
    }
}

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
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]){
            dfs(i,1);
        }
    }
    if(ansValid){
        for (int i = 1; i <= n; i++)
        {
            cout<<ans[i]<<" ";
        }
        
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}