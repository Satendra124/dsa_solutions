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
        double k1,k2,k3,v;
        cin>>k1>>k2>>k3>>v;
        double time =100.0/(k1*k2*k3*v);
        double olympicTime =  round( time * 100.0 ) / 100.0;
        if(olympicTime<9.58) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}