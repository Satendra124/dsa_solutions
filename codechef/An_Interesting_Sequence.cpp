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
        int k;
        cin>>k;
        ll sum = 0;
        for (int i = 1; i <= (2*k); i++)
        {
            sum += __gcd(k+i*i,2*i + 1);
            cout<<i<<" "<< __gcd(k+i*i,2*i + 1)<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}