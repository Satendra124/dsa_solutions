#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef unsigned long long int ll;
int main()
{
    fast;
    ll n,k,x;
    cin>>n>>k>>x;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll parts = 0;
    vector<ll> v;
    for (int i = 1; i < n; i++)
    {
        if(arr[i] - arr[i-1]>x) {
            v.push_back(arr[i]-arr[i-1]);
        }
    }
    ll ans = 0;
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if(k==0) break;
        ll req = (v[i]-1)/x;
        if(req<=k) {
            k-=req;
            ans++;
        }
        else break;
    }
    cout<<v.size() - ans+1<<endl;
    
    return 0;
}