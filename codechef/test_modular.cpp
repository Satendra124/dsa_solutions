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
        int n,m;
        cin>>n>>m;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int b = 0;
            for (int j = i+1; j <= n; j++)
            {
                if((m%i)%j==(m%j)%i){
                    cout<<i<<" "<<j<<endl;
                    ans++;
                    b++;
                }
            }
            //cout<<i<<" - "<<b<<endl;
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     cout<<i<<" - "<<m%i<<endl;
        // }
        
        cout<<ans<<endl;
    }
    return 0;
}