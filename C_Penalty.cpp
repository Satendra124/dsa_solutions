#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int dp[11][11][11];

int round(vector<int> p,int pos,string& s){
    int remrounds = s.size() - pos-1;
    if(pos==s.size()) return pos;
    if(dp[p[0]][p[1]][pos]!=-1) return dp[p[0]][p[1]][pos];
    if(p[pos%2]+1 + remrounds/2 < p[!(pos%2)]) return dp[p[0]][p[1]][pos]= pos;
    if(p[!(pos%2)] + (remrounds+1)/2 < p[pos%2]) return dp[p[0]][p[1]][pos] =pos;
    if(s[pos]=='1'){
        vector<int> ne = p;
        ne[pos%2]++;
        return dp[p[0]][p[1]][pos] =round(ne,pos+1,s);
    }else if(s[pos]=='0') return dp[p[0]][p[1]][pos]= round(p,pos+1,s);
    else {
        vector<int> ne = p;
        ne[pos%2]++;
        return dp[p[0]][p[1]][pos] = min(round(ne,pos+1,s),round(p,pos+1,s));
    }
}

void solve(){
    string s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<round({0,0},0,s)<<endl;
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