#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
unordered_map<ll,ll> dp;
ll solve(ll n){
    if(n==0) return 0;
    if(dp[n])
    return dp[n];
    else return dp[n] = max(n,solve(n/2)+solve(n/3)+solve(n/4));
} 
int main()
{
    fast;
    ll n;
    while (cin>>n)
    { 
        cout<<solve(n)<<endl;
    }
    return 0;
}