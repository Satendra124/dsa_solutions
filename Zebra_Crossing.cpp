#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int dp[1000][1000][2];

int solve(int cur,string& s,int k,int now){
    if(k==0) return cur;
    if(cur==s.size()) return -1e7;
    if(dp[cur][k][now]!=-1) return dp[cur][k][now];
    if(s[cur]!= now + '0') return dp[cur][k][now] = max(solve(cur+1,s,k-1,s[cur]-'0'),solve(cur+1,s,k,now));
    else return dp[cur][k][now]= solve(cur+1,s,k,now);
}

int slow(int n,int k,string s){
    memset(dp,-1,sizeof(dp));
    int ans = solve(0,s,k,s[0]-'0');
    if(ans<0) return -1;
    else return ans;
}
int fas(int n,int k,string s){
    int ans ;
    vector<int> arr;
    char last = s[0];
    for (int i = 1; i < n; i++)
    {
        if(last!=s[i]){
            arr.push_back(i-1);
            last = s[i];
        }
    }
    arr.push_back(n-1);
    //cout<<n-1<<endl;
    int max_jump = arr.size()-1;
    if(max_jump<k) return -1;
    else if(max_jump==k) return n;
    else{
        if(((s[0]!=s[n-1])&&(k%2!=0) ||((s[0]==s[n-1])&&(k%2==0))))
            return n;
        else return arr[arr.size()-2]+1;
    }
}
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        string s;
        cin>>n>>k;
        cin>>s;
        //k = 1+rand()%1000;
        //n = (k+rand()%1000)%1000;
        //if(k>n) k =n;
        //s = "";
        // for (int i = 0; i < n; i++)
        // {
        //     s.push_back('0'+rand()%2);
        // }
        // if(slow(n,k,s)!=fas(n,k,s)){
        //     cout<<n<<" "<<k<<endl;
        //     cout<<s<<endl;
        //     cout<<slow(n,k,s)<<" "<<fas(n,k,s)<<endl;
        // }
        cout<<fas(n,k,s)<<endl;
        
    }
    return 0;
}