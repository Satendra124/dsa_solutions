#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
map<int,ll> depth;
map<int,ll> child;
map<int,vector<int>> tre;
bool depthSort(int a,int b){
    //return depth[a]*child[a]>depth[b]*child[b];
    //if (child[a]>child[b]) return true;
    // else if(child[a]==child[b]){
    //     return depth[a]<depth[b];
    // }
    //else return false;
    return child[a]>child[b];
}
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        child.clear();
        tre.clear();
        depth.clear();
        int n,x;
        cin>>n>>x;
        for (int i = 0; i < n-1; i++)
        {
            int u,v;
            cin>>u>>v;
            tre[min(u,v)].push_back(max(v,u));
        }
        //find depth of each node
        //start from bottom
        for (int i = n; i > 0; i--)
        {
            ll d = 0;
            ll c = 0;
            for (int j = 0; j < tre[i].size(); j++)
            {
                d = max(d,depth[tre[i][j]]);
                c += 2* child[tre[i][j]];
            }
            depth[i] = d+1;
            child[i] = c+1;
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     cout<<depth[i]<<endl;
        // }
        // cout<<endl;
        //sort the map vectors according to their depths
        for (int i = 1; i <= n; i++)
        {
            sort(tre[i].begin(),tre[i].end(),depthSort);
        }
        //we start from node 1
        queue<pair<ll,ll>> q;
        ll sum = x;
        q.push({1,x});
        while(!q.empty()){
            pair<ll,ll> cur = q.front();
            q.pop();
            ll no = cur.second;
            for (int i = 0; i < tre[cur.first].size(); i++)
            {
                sum=(sum + (no*ll(i+1))%mod)%mod;
                q.push({tre[cur.first][i],(no*ll(i+1))%mod});
            }
        }
        cout<<sum%mod<<endl;
    }
    return 0;
}