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
    map<int,vector<int>> tree;
    vector<int> vals;
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int cur = 1;
    queue<vector<int>> q;
    q.push({1,-1,0});
    while (!q.empty())
    {
        vector<int> cur = q.front();q.pop();
        for (int i = 0; i < tree[cur[0]].size(); i++)
        {
            if(tree[cur[0]][i]!=cur[1]) q.push({tree[cur[0]][i],cur[0],cur[2]+1});
        }
        if(tree[cur[0]].size()==1 && cur[1]!=-1) vals.push_back(cur[2]);
    }
    ll sum = 0;
    for (int i = 0; i < vals.size(); i++) sum += vals[i];
    double ans = double(sum)/double(vals.size());
    cout<<ans<<endl;
    return 0;
}