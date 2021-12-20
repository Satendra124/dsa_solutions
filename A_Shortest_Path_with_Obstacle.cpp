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
        int xa,ya,xb,yb,xf,yf;
        cin>>xa>>ya>>xb>>yb>>xf>>yf;
        int ans = 0;
        if(xf>min(xa,xb)&&xf<max(xa,xb)&&ya==yb&&ya==yf) ans +=2;
        else if(yf>min(ya,yb)&&yf<max(ya,yb)&&xa==xb&&xa==xf) ans +=2;
        ans += abs(yb-ya) + abs(xb-xa) ;
        cout<<ans<<endl;
    }
    return 0;
}