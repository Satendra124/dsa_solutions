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
        int n;
        cin>>n;
        double a = log2(n);
        double b = log2(a);
        if(a != int(a)) cout<<"NO"<<endl;
        else{
            if(int(a)%4==0 || int(b)%4==0 || b==1 || a==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}