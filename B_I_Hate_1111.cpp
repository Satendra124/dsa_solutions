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
        string ans=  "YES";
        int n = s.length();
        for(int i=0;i<n-1;i++){
            if(s[i]>s[i+1]){
                ans = "NO";
                break;
            }
        }
        if(s[n-1]!=s[n-2]) ans = "NO";
        cout<<ans<<endl;
    }
    return 0;
}