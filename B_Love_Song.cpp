#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<ll> v;
    v.push_back(0);
    ll sum = 0;
   // v.push_back(sum);
    for(char c:s){
        sum += c - 'a' + 1;
        v.push_back(sum);
    }
    for (int i = 0; i < q; i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<v[r] - v[l-1]<<endl;
    }
    
    return 0;
}