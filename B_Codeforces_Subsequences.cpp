
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    	ll p=1,k;
	cin>>k;
	string s = "codeforces";
	vector<ll> v(10,1);
	for(ll i = 0; p < k; i = (i+1)%10){
		v[i]++;
		p = (v[i]*p)/(v[i]-1);
	}
 
	for(ll i=0;i<10;i++)
		while(v[i]--)
			cout<<s[i];
}