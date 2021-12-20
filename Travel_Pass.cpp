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
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        ll ans = 0;
        for(char& c:s){
            if(c=='0') ans += a;
            else ans += b;
        }
        cout<<ans<<endl;
    }
    return 0;
}