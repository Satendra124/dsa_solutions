// #include <bits/stdc++.h>
// using namespace std;
// int mod = 1e9+7;
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// typedef long long int ll;
// int n,m;
// map<int,vector<int>> graph;
// bool visited[100001];
// bool visited2[100001];
// vector<int> ans;
// int nodewithCycle = -1;

// void transverse(int cur,int last){
//     if(nodewithCycle!=-1) return;
//     else if(visited[cur]){
//         nodewithCycle = cur;
//         return;
//     }
//     visited[cur] = true;
//     for (int i = 0; i < graph[cur].size(); i++)
//     {
//         if(graph[cur][i]!=last) transverse(graph[cur][i],cur);
//     }
// }

// void dfs(int cur,vector<int> path,int last){
//     if(last!=-1&&cur==nodewithCycle){
//         //path.push_back(cur);
//         ans = path;
//         return;
//     }
//     else if(visited2[cur]) return;
//     visited2[cur] = true;
//     for (int i = 0; i < graph[cur].size(); i++)
//     {
//         path.push_back(graph[cur][i]);
//         if(last!=graph[cur][i]) dfs(graph[cur][i],path,cur);
//         path.pop_back();
//     }
    
// }

// int main()
// {
//     fast;
//     cin>>n>>m;
//     for (int i = 0; i < m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }
//     // transverse to find node with a cycle
//     for (int i = 1; i <= n &&(nodewithCycle==-1); i++)
//     {
//         transverse(i,-1);
//     }
//     if(nodewithCycle==-1){
//         cout<<"IMPOSSIBLE"<<endl;
//     }else{
//         dfs(nodewithCycle,{nodewithCycle},-1);
//         // int cur = nodewithCycle;
//         // vector<int> path;
//         // path.push_back(cur);
//         // visited2[cur] = true;
//         // for (int i = 0; i < graph[cur].size(); i++)
//         // {
//         //     path.push_back(graph[cur][i]);
//         //     dfs(graph[cur][i],path);
//         //     path.pop_back();
//         // }
//         cout<<ans.size()<<endl;
//         for (int i = 0; i < ans.size(); i++)
//         {
//             cout<<ans[i]<<" ";
//         }
//     }
// }


#include <bits/stdc++.h>
#define all(x)                x.begin(),x.end()
#define pb                    push_back
#define IOfast                ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
int visited[(int)2e5 + 1];
vector <int> graph[(int)2e5 + 1];
vector<int> path; // to keep track of paths
 
void dfs(int node,int par)
{
  visited[node] = 1;
  path.pb(node);
  for(auto &next:graph[node])
  {
    if(par == next) continue;
 
    if(visited[next])
    {
       path.pb(next);
       int i = (find(all(path),next) - path.begin());
       cout<<path.size() - i<<"\n";
 
       while(i<path.size())
         cout<<path[i++]<<" ";
 
       exit(0);
    }
    else
      dfs(next,node);
  }
  path.pop_back();
}
 
void solve()
{
  int n,m,u,v;
  cin>>n>>m;
 
  while(m--)
    cin>>u>>v , graph[u].pb(v) , graph[v].pb(u);
 
 for(int i = 1;i<=n;i++)
    if(visited[i] == 0)
       dfs(i,0);
 
 cout<<"IMPOSSIBLE";
}
 
int main()
{
  IOfast;
  solve();
 
  return 0;
}