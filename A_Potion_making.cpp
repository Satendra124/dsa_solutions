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
        int k;
        cin>>k;
        int gcd = __gcd(k,100-k);
        if(k==100){
            cout<<1<<endl;
        }else{
            cout<<k/gcd + (100-k)/gcd<<endl;
        }
    }
    return 0;
}