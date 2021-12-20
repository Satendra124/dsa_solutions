#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;


int primeFactors(int n)
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if(n%i==0) cnt++;
    }
    return cnt;
}


int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        int p  = __gcd(a,b);
        //cout<<p<<endl;
        //need to change a and b to p in exactly k steps
        int f1 = primeFactors(a/p);
        int f2 = primeFactors(b/p);
        int f3 = primeFactors(p);
        //cout<<f1<<" "<<f2<<" "<<f3<<endl;
        if(f1 + f2 + f3/2>=k){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}