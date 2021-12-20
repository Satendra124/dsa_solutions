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
        int n,p,x,y;
        cin>>n>>p>>x>>y;
        int line[n];
        for (int i = 0; i < n; i++)
        {
            cin>>line[i];
        }
        int ans = 0;
        for (int i = 0; i < p; i++)
        {
            if(line[i]){
                ans +=y;
            }else ans +=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}