#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int calcu(ll i,ll G){
    ll fin = 2*G - ((i*(i-1)));
    //cout<<i<<" "<<G<<" "<<fin<<endl;
    if(fin<=0) return -1;
    if(fin%(2*i)==0) return 1;
    return 0;
}

int main()
{
    fast;
    int t;
    cin>>t;
    int p = t;
    while (t--)
    {
        ll n;
        cin>>n;
        int ans=  0;
        for (int i = 1;i<=n; i++)
        {
            int c = calcu(i,n);
            if(c<0) break;
            if(c==0) continue;
            //cout<<i<<endl;
            ans++;
        }
         cout<<"Case #"<<p - t<<": "<<ans<<endl;
    }
    return 0;
}