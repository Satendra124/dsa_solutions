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
        int n,x,k;
        cin>>n>>x>>k;
        string ans = "NO";
        if(x%k==0) ans = "YES";
        if((n+1-x)%k==0) ans = "YES";
        cout<<ans<<endl;
    }
    return 0;
}