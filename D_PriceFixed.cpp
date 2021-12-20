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
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        int b,a;
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    int items = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(items + v[i].second < v[i].first){
            //just buy as it is
            ans += v[i].second * 2;
            items += v[i].second;
        }else{
            //buy to avail the offer
            int toBuy = max(0, v[i].first-items) ;
            ans += toBuy*2;
            items += toBuy;
            //buy rest at offer
            ans += v[i].second - toBuy;
            items += v[i].second - toBuy;
        }
    }
    cout<<ans<<endl;
    return 0;
}