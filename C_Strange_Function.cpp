#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef unsigned long long int ll;
int main()
{
    fast;

    ll facts[19];
    facts[0] = 1;
    for (int i = 1; i < 19; i++)
    {
        facts[i] = facts[i-1]*i;
    }
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll sum =0 ;
        for (int i = 1; i < 19; i++)
        {
            sum += (n/facts[i]);
        }
        cout<<sum<<endl;
    }
    return 0;
}