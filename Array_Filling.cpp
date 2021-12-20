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
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> ops;
        for (int i = 0; i < m; i++)
        {
            int x,y;
            cin>>x>>y;
            ops.push_back({x,y});
        }
        sort(ops.begin(),ops.end(),greater<pair<int,int>>());
        long long lcm = 1;
        long long left = n;
        long long ans  =0 ;
        for (int i = 0; i < m && left>0; i++)
        {
            long long x = ops[i].first,y = ops[i].second;
            lcm = lcm*y/__gcd(lcm,y);
            ans += (left - n/lcm)*x;
            left = n/lcm;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}