#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    fast;
    int mod = 1e9+7;
    int n,x;
    cin>>n>>x;
    int coins[n];
    for (int i = 0; i < n; i++)
    {
        cin>>coins[i];
    }
    
    int dp[x+1];
    dp[0] = 1;
    
    for (int i = 1; i < x+1; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if(coins[j]<=i){
                (dp[i] += dp[i-coins[j]])%=mod;
            }
        }
        
    }
    cout<<dp[x];
    
}