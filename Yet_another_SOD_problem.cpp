#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef unsigned long long int ll;

ll slow(ll l,ll r){
    ll ans=  0;
    for (int i = l; i <= r; i++)
    {
        if(i%3==0) ans++;
    }
    return ans;
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        ll l,r;
        cin>>l>>r;
        //l = rand()%10000;
        //r = l+ rand()%10000;
        if(l%3!=0) l += 3 - l%3;
        r -= r%3;
        ll ans = 1 + (r-l)/3;
        // if(ans!=slow(l,r)) {
        //     cout<<slow(l,r)<<endl;
        //     cout<<ans<<endl;
        //     cout<<l<<" "<<r<<endl;
        //     cout<<"SDA"<<endl;
        // }
        //cout<<"DONE"<<endl;
        if(l>r) ans = 0;
        cout<<ans<<endl;
    }
    return 0;
}