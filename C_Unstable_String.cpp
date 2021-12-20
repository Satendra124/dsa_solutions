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
        string s;
        cin>>s;
        ll c = 0;
        ll ans = 0;
        //1 will be at odd positions  0 at even pos ? anywhere
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='1' && i%2) c++;
            else if(s[i]=='0' && i%2==0) c++;
            else if(s[i]=='?') c++;
            else{
                ans += c*(c+1)/2;
                c = 0;
            }
        }
        ans += c*(c+1)/2;
        c = 0;
        //1 will be at even positions  0 at odd pos ? anywhere
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='0' && i%2) c++;
            else if(s[i]=='1' && i%2==0) c++;
            else if(s[i]=='?') c++;
            else{
                ans += c*(c+1)/2;
                c = 0;
            }
        }
        ans += c*(c+1)/2;
        c = 0;
        //odd + even - cons ?
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='?') c++;
            else{
                ans -= c*(c+1)/2;
                c = 0;
            }
        }
        ans -= c*(c+1)/2;
        c = 0;
        cout<<ans<<endl;
    }
    return 0;
}