#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef unsigned long long int ll;
int main()
{
    fast;
    ll c[3];
    cin>>c[0]>>c[1]>>c[2];
    int ans = 0;
    ll a = INT_MAX;
    for (int i = 0; i < 3; i++)
        a = min(c[i],a);
    
    ans += a;
    for (int i = 0; i < 3; i++)
        c[i] -=a;
    sort(c,c+3);
    int b = min(c[1]/3,c[2]/3);
    ans += 2*b;
    c[1] -= b*3;
    c[2] -= b*3;
    sort(c,c+3);
    int d = min(c[1],c[2]/2);
    ans += d;

    cout<<ans<<endl;
    return 0;
}