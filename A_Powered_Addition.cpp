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
        int n;
        cin >> n;
        int mx;
        cin >> mx;
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x;
            cin >> x;
 
            if (x < mx)
            {
                int k = mx - x;
                int c = 0;
                while (k)
                {
                    k /= 2;
                    c++;
                }
                ans = max(ans, c);
            }
            else
            {
                mx = x;
            }
        }
 
        cout << ans << endl;
    }
    return 0;
}











// while(--n){
        //     ll cur;
        //     cin>>cur;
        //     k = last-  cur;
        //     //cout<<"h:"<<k<<endl;
        //     last = cur;
        //     if(k<=0) {
        //         continue;
        //     }
        //     if(log2(k)-(ll)(log2(k)) !=0.0){
        //         k -= total;
        //         k = pow(2,ll(log2(k))+1);
        //        // cout<<"HERE: "<<k<<endl;
        //     }
        //     last = cur + k;
        //     total += k;
        // }
        // if(k>0)
        // cout<<(ll)(log2(k))+1<<endl;
        // else cout<<0<<endl;