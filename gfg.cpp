// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
    pair<int,int> cntWays(string& s,int l,int r){
        if(dp[l][r][0]!=-1) return {dp[l][r][0],dp[l][r][1]};
        if(l==r){
            if(s[l]=='T') return {0,1};
            else return {1,0};
        }
        pair<int,int> cnt = {0,0};
        
        for(int k=l;k<r-1;k+=2){
            char op = s[k+1];
            
            pair<int,int> t1 = {dp[l][k][0],dp[l][k][1]};
            if(dp[l][k][0]==-1) t1 = cntWays(s,l,k);
            dp[l][k][0] = t1.first;
            dp[l][k][1] = t1.second;
            pair<int,int> t2 = {dp[k+2][r][0],dp[k+2][r][1]};
            if(dp[k+2][r][0]==-1) t2 = cntWays(s,k+2,r);
            dp[k+2][r][0] = t2.first;
            dp[k+2][r][1] = t2.second;
            // we have number of true and false possible for each substring
            if(op=='&'){
                cnt.first += t1.first * (t2.first+t2.second) + t2.first*(t1.first+t1.second);
                cnt.second += t1.second*t2.second;
            }
            else if(op=='|'){
                cnt.first += t1.first * t2.first;
                cnt.second += t1.second * (t2.first+t2.second) + t2.second*(t1.first+t1.second);
            }
            else if(op=='^'){
                cnt.first += t1.first*t2.first + t1.second*t2.second;
                cnt.second += t1.first*t2.second + t1.second*t2.first;
            }else{
                cout<<"error"<<endl;
            }
        }
        dp[l][r][0] = cnt.first;
        dp[l][r][1] = cnt.second;
        return cnt;
    }

    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return cntWays(S,0,N-1).second;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends