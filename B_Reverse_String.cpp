#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int dp[501][1001][2];
bool lo(string& s,string& t,int a,int b,bool ending){
    if(b==t.length()) return true;
    if(a==s.length() || a<0) return false;
    if(s[a]!=t[b]) return false;
    if(dp[a][b][ending]!=-1) return dp[a][b][ending];
    if(!ending)  return dp[a][b][ending]= lo(s,t,a-1,b+1,true) || lo(s,t,a+1,b+1,false);
    else return dp[a][b][ending] = lo(s,t,a-1,b+1,true);
}

void solve(){
    string s;
    string t;
    cin>>s;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    bool ans = false;
    for (int i = 0; i < s.length(); i++)
    {
        ans = ans || lo(s,t,i,0,false);
    }
    
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}