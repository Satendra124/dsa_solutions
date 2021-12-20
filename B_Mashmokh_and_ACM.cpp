#include <bits/stdc++.h>
using namespace std;

int dp[2000];

// int solve(int start,int n,int k,int last){
//     cout<<"Called for: "<<"start: "<<start<<" k: "<<k<<" last: "<<last<<endl;
//     if(k==0) {
//         cout<<"here "<<last<<" "<<start<<endl;
//         return 1;
//     }
//     if(start>n) return 0;
//     if(dp[n][k]==-1){
//         if(last==-1||start%last==0){
            
//             return solve(start,n,k-1,start)+solve(start+1,n,k,last);
//         }else{
//             return solve(start+1,n,k,last);
//         }
//     }else{
//         return dp[n][k];
//     }
    
// }

int main()
{   
    int n,k;
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
    {
        dp[i] =1;
        cout<<i<<" "<<i<<endl;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2*i; j <= n; j+=i)
        {
            cout<<i<<" "<<j<<endl;
            dp[j]+=dp[i]+1;
        } 
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<dp[i]<<" ";
    }
}