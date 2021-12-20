#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int dp[100001][2];
int solve(string &s,int cur,bool rev){
    if(cur==s.size()) return 0;
    if(dp[cur][rev]!=-1) return dp[cur][rev];
    if((s[cur]=='1' && !rev) || (rev && s[cur]=='0')) return dp[cur][rev] = solve(s,cur+1,rev);
    return dp[cur][rev] = 1 + solve(s,cur+1,!rev);
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        //memset(dp,-1,sizeof(dp));
        string s;
        cin>>s;
        //cout<<solve(s,0,false)<<endl;
        bool rev = false;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if((s[i]=='1' && !rev) || (rev && s[i]=='0')) continue;
            else{
                rev = !rev;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}