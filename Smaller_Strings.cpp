#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

ll power(long long x, unsigned int y, int p)
{
    ll res = 1;   
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    fast;
    int t;
    cin>>t;
    int p = t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll ans = 0;
        int mid = (n-1)/2;
        for(int i=0;i<=mid;i++){
            ll other = s[i] - 'a';
            ans =(ans + (other*(power(k,mid-i,mod)))%mod)%mod;
        }
        string pali = "";
        for (int i = 0; i <=mid; i++)
        {
            pali.push_back(s[i]);
        }
        for(int i=mid+1;i<n;i++) pali.push_back(s[n-i-1]);
        //cout<<pali<<endl;
        if(pali<s) {
            ans++;
            //cout<<"helomf"<<endl;
        }
        cout<<"Case #"<<p - t<<": "<<ans%mod<<endl;
    }
    return 0;
}