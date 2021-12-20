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
    map<int,vector<int>> graph;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    map<int,bool> visited;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        else visited[i] = true;
        int start = i;
        int cur = i;
        bool isAns = true;
        int last = 0;
        while(true){
            int next = 0;
            if(graph[cur].size()==2){
                if(last!=graph[cur][1]) next = graph[cur][1];
                else if(last!=graph[cur][0]) next = graph[cur][0];
                else{
                    isAns = false;
                    break;
                }
            }
            if(start==next){
                break;
            }
            last = cur;
            cur = next;
            if(visited[cur]){
                isAns = false;
                break;
            }
            else visited[cur] = true;
            
        }
        //if (isAns) cout<<i<<endl;
        ans += isAns;
    }
    cout<<ans<<endl;
    return 0;
}