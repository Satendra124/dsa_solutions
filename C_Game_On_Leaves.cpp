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
        int n,x;
        cin>>n>>x;
        map<int,vector<int>> tree;
        for (int i = 0; i < n-1; i++)
        {
            int u,v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        //check if x is a leave currently 
        if(tree[x].size()<=1) cout<<"Ayush"<<endl;
        else{
            if((n-3)%2==0) cout<<"Ashish"<<endl;
            else cout<<"Ayush"<<endl;
        }
    }
    return 0;
}