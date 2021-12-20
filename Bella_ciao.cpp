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
        ll D,d,P,Q;
        cin>>D>>d>>P>>Q;
        ll m = 0;
        ll n = (D/d);
        m += (n)*d*P;
        m += d*Q*n*(n-1)/2;
        m += (D%d)*(P + (n)*Q);
        cout<<m<<endl;
    }
    return 0;
}