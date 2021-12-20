#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int childAlloc(map<int,vector<int>>& tree,vector<int>& childs,int cur,int last){
    int ans =0;
    for(int next:tree[cur]){
        if(next!=last){
            if(childAlloc(tree,childs,next,cur)==0){
                ans++;
            }
        }
    }
    childs[cur] = ans;
    cout<<cur<<" "<<ans<<endl;
    return ans;
}

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
        vector<int> childs(n+1,0);
        childAlloc(tree,childs,1,-1);
        int ans = 0;
        for (int i = 2; i < n+1; i++)
        {
            ans += max(0,childs[i]-1);
        }
        cout<<ans+1<<endl;
    }
    return 0;
}