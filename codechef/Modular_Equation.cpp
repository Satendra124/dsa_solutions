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
        ll n,m;
        cin>>n>>m;
        map<int,int> rems;
        for (int i = 1; i <= n; i++)
        {
            rems[m%i]++;
        }
        for (int b = 1; b <= n; b++)
        {
            // m%a == (m%b)%a
            //find how may a possible so that m%a == x%a ... x = m%b
        }
        
    }
    return 0;
}