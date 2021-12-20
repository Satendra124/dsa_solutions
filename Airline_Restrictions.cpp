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
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        bool ans = false;
        //ab in check in
        if(a+b<=d && c<=e) ans = true;
        //bc in ci
        if(b+c<=d && a<=e) ans = true;
        //ac in ci
        if(a+c<=d && b<=e) ans = true;
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}