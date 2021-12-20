//TLE


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[200000];

int getHappiness(int start,int arr[],int n,int lasti){
    if(start>n-1) return 0;
    if(lasti==-1||start-lasti == arr[start]-arr[lasti]){
        if(dp[start]==-1) dp[start] = getHappiness(start+1,arr,n,start)+arr[start];
            return max(dp[start],getHappiness(start+1,arr,n,lasti));
    }else{
        return getHappiness(start+1,arr,n,lasti);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) cin>>arr[i];
    for (int i = 0; i < n; i++) dp[i] = -1;
    cout<<getHappiness(0,arr,n,-1)<<endl;
    // for (int i = 0; i < n; i++) cout<<dp[i]<<" ";
    // cout<<endl;
    return 0;
}