#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n,m,p;
    cin>>n>>m>>p;
    string peps[n];
    for (int i = 0; i < n; i++)
    {
        cin>>peps[i];
    }
    vector<int> ans(m,0);
    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if(peps[j][i]=='1') cnt++;
        }
        if(cnt>=(n+1)/2) ans[i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cout<<ans[i];
    }
    
    return 0;
}