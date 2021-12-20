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
        ll arr[n][2];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i][0]>>arr[i][1];
        }
        ll b = 0;
        if(arr[0][0]>arr[n-1][1]) {
            b+=arr[0][0] - arr[n-1][1];
            arr[0][0] -= arr[0][0] - arr[n-1][1];
        }
        ll initializer = arr[0][0];
        for (int i = 1; i < n; i++)
        {
            if(arr[i][0]>arr[i-1][1]) {
                b+=arr[i][0] - arr[i-1][1];
                arr[i][0] -= arr[i][0] - arr[i-1][1];
            }
            initializer = min(initializer,arr[i][0]);
        }
        cout<<b+initializer<<endl;
    }
    return 0;
}