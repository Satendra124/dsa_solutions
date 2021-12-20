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
        ll n,a,b;
        cin>>n>>a>>b;
        bool ans = false;

        if(a==1){
            if((n-1)%b==0) ans = true;
            else ans = false;
        }

        while(a!=1 && n>1){
            if(n%a==0) n /= a;
            else{
                // if((n%a)%b==0) n -= n%a;
                // else{
                //     ans = false;
                //     break;
                // }
                n -= (((n%a)/b)+1)* b;
            }
        }
        if(n==1) ans = true;
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}