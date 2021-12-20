#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef unsigned long long int ll;
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        ll o = 0,z=0;
        for (int i = 0; i < n; i++)
        {
            int temp ; 
            cin>>temp;
            if(temp==0) z++;
            else if(temp==1) o++;   
        }
        ll ans = pow(2,z)*o;
        cout<<ans<<endl;
    }
    return 0;
}