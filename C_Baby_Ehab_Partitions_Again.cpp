#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;


int canBeDivided(vector<int> arr){
    int sum = 0;
    for(int i:arr) sum+=i;
    if(sum%2!=0) return -1;
    sum = sum/2;
    bool dp[100];
    dp[0] = true;
    int n = arr.size();
    for(int i=1 ; i <= n;i++){
        for(int j = sum; j>=0; j--){
            if(j-arr[i-1] >= 0){
                dp[j] = dp[j - arr[i-1]] || dp[j];
            }
        }
    }
    return dp[sum];
}

int main()
{
    fast;
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    //just need to find if it is good or not
    //if it is not good remove a element
    //else print zero
    int ans = canBeDivided(arr);
    if(ans!=-1){
        cout<<ans<<endl<<1<<endl;
    }else cout<<0<<endl;
    
    return 0;
}