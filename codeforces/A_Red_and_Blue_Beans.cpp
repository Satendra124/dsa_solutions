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
        int r,b,d;
        cin>>r>>b>>d;
        ll m = min(r,b);
        ll M = max(r,b);
        if(M<=(d+1)*m) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}