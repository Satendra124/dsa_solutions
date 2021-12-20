#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int dp[1000001];

int getMinSteps(int n){
    if(dp[n]!=-1) return dp[n];
    if(n==0) return 0;
    if(n<0) return 1e7;
    if(n%2==0) return dp[n] = 1 + min(getMinSteps(n-1),getMinSteps(n/2));
    else return dp[n] = 1 + getMinSteps(n-1);
}

int main()
{
    fast;
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<getMinSteps(n)<<endl;
    return 0;
}