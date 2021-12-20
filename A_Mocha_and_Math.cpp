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
        cin>>n;
        int maxNO = INT_MIN;
        int minNo = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            if(ans==-1) ans = temp;
            else ans &= temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}