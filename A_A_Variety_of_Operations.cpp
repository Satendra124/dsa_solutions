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
        int c,d;
        cin>>c>>d;
        int ans = 0;
        if(c>0 || d>0) ans++;
        int p = abs(c-d);
        if(p%2!=0){
            cout<<-1<<endl;
            continue;
        }
        if(p>0) ans++;
        cout<<ans<<endl;
    }
    return 0;
}