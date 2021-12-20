#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n;
    cin>>n;
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    map<int,vector<int>> tree;
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]){
            visited[i] = true;
            cout<<"? "<<i<<endl;
            int dist[n+1];
            for (int j = 1; j <= n; j++)
            {
                cin>>dist[j];
                if(dist[j]==1){
                    tree[min(i,j)].push_back(max(i,j));
                    visited[j] = true;
                }
            } 
        }
    }
    for (int i = 1; i <= n; i++)
    {
        unique(tree[i].begin(),tree[i].end());
    }
    cout<<"!"<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < tree[i].size(); j++)
        {
            cout<<i<<" "<<tree[i][j]<<endl;
        }
    }
    
    return 0;
}