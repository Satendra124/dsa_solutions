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
        ll n;
        cin>>n;
        if(n==0) return 0;
        ll k = log10(n);
        ll ans = k*9;
        for(int i =1;i<10;i++){
            ll no = stoll(string(k+1,i+'0'));
            //cout<<"no: "<<no<<" "<<n<<endl;
            if(n>=no) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}