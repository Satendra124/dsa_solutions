#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    ll n,w;
    cin>>n>>w;
    ll woods[n];
    for (int i = 0; i < n; i++)
    {
        cin>>woods[i];
    }
    sort(woods,woods+n);
    ll wp[n];
    wp[n-1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        wp[i] = woods[i]-woods[i+1] + wp[i+1];
    }
    int ans = -1;
    int l = 0;
    int r = n;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(wp[mid]>=w) {
            l = mid+1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    //cout<<ans<<endl;
    cout<<woods[ans]<<endl;
    
    return 0;
}