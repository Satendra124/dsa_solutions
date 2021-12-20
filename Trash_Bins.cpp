#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int t;
    int d;
    cin>>t;
    d=  t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l[n];
        int r[n];
        int last = -1;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='1') last = i;
            l[i] = last;
            
        }
        last = -1;
        for (int i = n-1; i >= 0; i--)
        {
            if(s[i]=='1') last = i;
            r[i] = last;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(l[i]==-1){
                ans += r[i] - i;
            }else if(r[i]==-1){
                ans += i - l[i];
            }else{
                ans += min(r[i] - i,i - l[i]);
            }
        }
        cout<<"Case #"<<d - t<<": "<<ans<<endl;
        
    }
    return 0;
}