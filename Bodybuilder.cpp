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
        ll n,r;
        cin>>n>>r;
        ll a[n],b[n];
        for (int i = 0; i < n; i++) cin>>a[i];
        for (int i = 0; i < n; i++) cin>>b[i];

        ll T = 0;
        ll mT = 0;
        for (int i = 0; i < n; i++)
        {

            T += b[i];
            mT = max(mT,T);
            if(i<n-1) T -= r*(a[i+1]-a[i]);
            T = max(T,0ll);
        }
        cout<<mT<<endl;
        
    }
    return 0;
}