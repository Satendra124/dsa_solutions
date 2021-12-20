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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        string ans = "NO";
        int cons = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='*') cons++;
            else cons = 0;
            if(cons==k){
                ans = "YES";
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}