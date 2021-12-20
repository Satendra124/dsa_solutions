#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef unsigned long long int ull;
ull nearest10(ull n){
    if(n==0) return 0;
    ull k = log10(n);
    return pow(10,k);
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        ull n;
        cin>>n;
        int k = 0;
        while (n>=2050)
        {
            k++;
            n -= 2050 * nearest10(n/2050);
            //cout<<"n: "<<n<<endl;
        }
        if(n==0) cout<<k<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}