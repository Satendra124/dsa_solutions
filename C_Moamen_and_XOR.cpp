#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        int ans = 0;
        int prod = 1;
        for(int i=1;i<=k;i++){
            //lets say this is the bit where the and will surpass xor
            //to do so in and all once and in xor there are even 1s
            int ways = 0;
            if(n)
            ans += prod*ways;
            //equals
            //and - 1 --- xor - odd number of ones
            //ways = 1*(n+1)/2;
            // ans ->0 ---- xor - even number of onces
            ways += (n+1)*(n+1)/2;
            prod *= ways;
        }
        ans += prod;
        cout<<ans<<endl;
    }
    return 0;
}