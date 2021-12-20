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
        int n,m,k;
        cin>>n>>m>>k;
        ll mi = min(n,m);
        ll ma = max(n,m);
        if(ma-1 +(mi-1)*ma >= k && mi-1 + (ma-1)*mi <=k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}