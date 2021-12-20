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
        int a,b,c;
        cin>>a>>b>>c;
        int primes[9] = {2,11,101,1009,10007,100003,1000003,10000019,100000007};
        int nos[9] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};
        int gcd = primes[c-1];
        cout<<gcd * pow(2,log2(nos[a-1]/gcd)+1)<<" "<<gcd * pow(3,(log(nos[b-1]/gcd)/log(3))+1)<<endl;
    }
    return 0;
}