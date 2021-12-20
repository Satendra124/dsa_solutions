#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

  

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        ll a=1,b=1,c=1;
        bool ans = false;
        for (ll i = (n/2); (i >0)&&!ans; i--)
        {
                ll j = i;
                ll k = n - i - j;
                if(k>0&&(i%k==0||k%i==0)){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    ans  = true;
                }
            
        }
        
    }
    return 0;
}