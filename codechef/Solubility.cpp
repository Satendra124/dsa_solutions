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
        ll x,a,b;
        cin>>x>>a>>b;
        cout<<10*(a + (100-x)*b)<<endl;
    }
    return 0;
}