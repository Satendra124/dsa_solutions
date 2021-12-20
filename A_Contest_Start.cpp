#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef unsigned long long int ll;
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        ll n,x,t;
        cin>>n>>x>>t;
        ll p = t/x;
        ll ans ;
        if(n>p) ans = (p*(p+1))/2 + p*(n-p-1);
        else ans = n*(n-1)/2;
        cout<<ans<<endl;
    }
    return 0;
}