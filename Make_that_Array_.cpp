#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int sumS()

void solve(){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];    
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];    
    }
    map<int,vector<int>> a_map;
    for (int i = 0; i < n; i++)
    {
        a_map[a[i]].push_back(i);
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // b[i]
        int index = a_map[b[i]].back();
        a_map[b[i]].pop_back();
        ans += sumS(index+1,i);
        updateS(index,i);
    }
    cout<<ans<<endl;
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}