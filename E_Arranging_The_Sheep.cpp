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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if(s[i]=='*')
                cnt++;
        int mid = (cnt+1)/2;
        int midI = -1;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='*')
            {
                p++;
                if(p==mid) midI = i;
            } 
        }
        p =0;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='*'){
                p++;
                if(p<mid){
                    ans += abs(midI-(mid-p)-i);
                }else{
                    ans += abs(midI+(p-mid)-i);
                }
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}