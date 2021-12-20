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
        ll n;
        cin>>n;
        // n = A*11 + B*111
        bool ansGot = false;
        for (ll i = 0; i < 20; i++)
        {
            if (n%11==0){
				ansGot = true;
			}
			n-=111;
			if (n<0) break;
		}

        if(ansGot) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}