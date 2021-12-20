#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n;
    cin>>n;
    char grid[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>grid[i][j];
        } 
    }
    ll dp[n][n];
    if(grid[0][0]=='.') dp[0][0] = 1;
    else dp[0][0] = 0;
    for (int i = 1; i < n; i++)
    {
        if(grid[0][i]=='.') dp[0][i] = dp[0][i-1];
        else dp[0][i] = 0;
        if(grid[i][0]=='.') dp[i][0] = dp[i-1][0];
        else dp[i][0] = 0;
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(grid[i][j]=='*') dp[i][j]=0;
            else{
                (dp[i][j] = dp[i-1][j] + dp[i][j-1])%=mod;
            }
        }
        
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}