#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef unsigned long long int ll;
ll mod = 1e9+7;
int main()
{
    fast;
    int n;
    cin>>n;
    if(n==1){ cout<<0<<endl; return 0;}
    ll nos[4] = {1,1,1,0};
    for (int i = 2; i < n; i++)
    {
        ll m = (nos[0]+nos[1]+nos[2])%mod;
        ll n = (nos[0]+nos[1]+nos[3])%mod;
        nos[0] = nos[1] = nos[2] = n;
        nos[3] = m;
    }
    cout<<(nos[0]+nos[1]+nos[2])%mod<<endl;
    return 0;
}