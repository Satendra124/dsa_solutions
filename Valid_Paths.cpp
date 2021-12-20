#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        map<int,vector<int>> tree;
        for (int i = 0; i < n-1; i++)
        {
            int u,v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        //lets say 1 is root
        queue<vector<int>> q;
        q.push({1,1,-1});//cur - level - last
        int ans = 0;
        while (!q.empty())
        {
            vector<int> cur =  q.front();q.pop();
            ans += cur[1];
            for (int i = 0; i < tree[cur[0]].size(); i++)
            {
                if(tree[cur[0]][i]!=cur[2]) q.push({tree[cur[0]][i],cur[1]+1,cur[0]});
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}