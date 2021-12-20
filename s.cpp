#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
vector<vector<int>> dp;
int solve(int xor_cur,int cur,int m,int arr[]){
    if(cur==0 && xor_cur>=m) return 1;
    if(cur==0) return 0;
    if(dp[xor_cur][cur]!=-1) return dp[xor_cur][cur];
    return dp[xor_cur][cur] = solve(xor_cur^arr[cur-1],cur-1,m,arr) + solve(xor_cur,cur-1,m,arr);
}

int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    int arr[n];
    dp = vector<vector<int>>(n+1,vector<int>(100000,-1));
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<solve(0,n,m,arr)<<endl;

    return 0;
}