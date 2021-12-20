#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
ll mod = 1e9+7;
ll power(ll x, ll y,ll p)
{
    ll res = 1;
 
    x = x % p; 
  
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        cout<<power(2,n-1,mod)<<endl;
    }
    return 0;
}