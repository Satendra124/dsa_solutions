#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll ans = LONG_LONG_MAX;
    for (int c = 0; pow(c-1,n-1) <= arr[n-1]; c++)
    {
        ll tempAns = 0;
        for (int i = 0; i < n; i++)
        {
            tempAns += abs(arr[i]-pow(c,i));
            if(tempAns>=ans) break;
        }
        ans = min(tempAns,ans);
    }
    cout<<ans<<endl;
    
    return 0;
}