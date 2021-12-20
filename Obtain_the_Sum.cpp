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
        ll n,s;
        cin>>n>>s;
        ll x = n*(n+1)/2 - s;
        if(x>=1 && x<=n) cout<<x<<endl;
        else cout<<-1<<endl;
        
    }
    return 0;
}