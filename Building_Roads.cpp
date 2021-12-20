#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int n,m;
map<int,vector<int>> graph;
bool visited[100005];

void iterate(int i,int last){
    if(i>n) return;
    else if(visited[i]) return;

    visited[i] = true;


    for (int j = 0; j < graph[i].size(); j++)
    {
        if(last!=graph[i][j]) iterate(graph[i][j],i);
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
    //for each points iterate its component
    vector<int> comps;
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]){
            comps.push_back(i);
            iterate(i,-1);
        }
    }
    if(comps.size()>1){
        cout<<comps.size()-1<<endl;
        for (int i = 0; i < comps.size()-1; i++)
        {
            cout<<comps[i]<<" "<<comps[i+1]<<endl;
        }
    }else cout<<0<<endl;
    
    

    return 0;
}