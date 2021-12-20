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
        // for (int i = 1; i < 1000000000; i++)
        // {
        //     ll n = i;
        //     ll p = log2(n);
        //     ll ans1 = ll(pow(2ll,p)-1);
        //     ll s = n;
        //     while(s){
        //         s &= --n;
        //     }
        //     ll ans2 = n;
        //     if(ans1!=ans2){
        //         cout<<i<<endl;
        //         cout<<ans1<<" "<<ans2<<endl;
        //     }
        //     //cout<<endl;
        //     if(i%100000==0) cout<<"PASS"<<i<<endl;
        // }
        ll n;
        cin>>n;
        ll p = log2(n);
        ll ans1 = ll(pow(2ll,p)-1);
        cout<<ans1<<endl;
    }
    return 0;
}