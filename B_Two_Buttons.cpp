#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int dp[20001];
bool visited[10001];
int solve(int n,int m){
    if(n<=0) return 1e7;
    if(n==m) return 0;
    if(dp[n]!=-1) return dp[n];
    if(visited[n]) return 1e7;
    visited[n] = true;
    if(n<m){
        return dp[n] =  1 + min(solve(n*2,m),solve(n-1,m));
    }else return dp[n] =  n-m;
}

int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    memset(visited,false,sizeof(visited));
    cout<<solve(n,m)<<endl;

}