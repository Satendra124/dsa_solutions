#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
vector<vector<int>> dp;
int arr[2001];
int n;
int iter(int cur,ll points,int potions){
    if(cur==n) return potions;
    if(dp[cur][potions]) return dp[cur][potions];
    if(points+arr[cur]>=0){
        return dp[cur][potions] = max(iter(cur+1,points+arr[cur],potions+1),iter(cur+1,points,potions));
    }else{
        return dp[cur][potions] = iter(cur+1,points,potions);
    }
}

int main()
{
    fast;
    cin>>n;
    dp = vector<vector<int>>(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<iter(0,0,0)<<endl;
    return 0;
}