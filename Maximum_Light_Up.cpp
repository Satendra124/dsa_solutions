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
        ll p,a,b,c,x,y;
        cin>>p>>a>>b>>c>>x>>y;
        cout<<max(p/(b+x*a),p/(c+y*a))<<endl;
    }
    return 0;
}