#include <bits/stdc++.h>
using namespace std;

int dp[100][4];


int minRest(int arr[],int start,int n,int last){

    if(start==n) return 0;
    if(arr[start]==0){
        //nothing open
        if(dp[start][0]==-1) dp[start][0] = minRest(arr,start+1,n,0)+1;
        return dp[start][0];
    }else if(arr[start]==1){
        //only contest
        if(last==1){
            if(dp[start][1]==-1) dp[start][1] = minRest(arr,start+1,n,0)+1;
            return dp[start][1];
        }
        if(dp[start][2]==-1) dp[start][2] = min(minRest(arr,start+1,n,1),1 +minRest(arr,start+1,n,0));
        dp[start][0] = dp[start][2];
        return dp[start][2];
    } else if(arr[start]==2){
        //only gym
        if(last==2){
            if(dp[start][2]==-1) dp[start][2] = minRest(arr,start+1,n,0)+1;
            return dp[start][2];
        }
        if(dp[start][1]==-1) dp[start][1] = min(minRest(arr,start+1,n,2),1 +minRest(arr,start+1,n,0));
        dp[start][0] = dp[start][1]; 
        return dp[start][1];
    }else{
        if(last==1){
            if(dp[start][1]==-1) dp[start][1] = min(minRest(arr,start+1,n,2),1 +minRest(arr,start+1,n,0));
            return dp[start][1];
        }else if(last==2){
            if(dp[start][2]==-1) dp[start][2] = min(minRest(arr,start+1,n,1),1 +minRest(arr,start+1,n,0));
            return dp[start][2];
        }else{
            if(dp[start][0]==-1) dp[start][0] = min(min(minRest(arr,start+1,n,2),1 +minRest(arr,start+1,n,0)),min(minRest(arr,start+1,n,1),1 +minRest(arr,start+1,n,0)));
            return dp[start][0];
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dp[i][j]=-1;
        }
    }
    int last = 0;
    cout<<minRest(arr,0,n,last);
}