#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[100000][2];
ll solve(int arr1[],int arr2[],int a,int lastArr,int n){
    if(a==n) return 0;
    if(lastArr==0){
        return max(solve(arr1,arr2,a,1,n),solve(arr1,arr2,a,2,n));
    }else if(lastArr==1){
        if(dp[a][1]==-1) dp[a][1] = max(solve(arr1,arr2,a+1,2,n)+arr2[a],solve(arr1,arr2,a+1,1,n));
        return dp[a][1];
    }else{
        if(dp[a][0]==-1) dp[a][0] = max(solve(arr1,arr2,a+1,1,n)+arr1[a],solve(arr1,arr2,a+1,2,n));
        return dp[a][0];
    }
}

int main()
{
    for (int i = 0; i < 100000; i++)
    {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    
    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>arr2[i];
    }
    cout<<solve(arr1,arr2,0,0,n);
}