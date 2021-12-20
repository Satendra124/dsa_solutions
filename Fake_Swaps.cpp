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
        string s,p;
        cin>>s;
        cin>>p;
        int op = 0;
        int zp = 0;
        int os = 0;
        int zs = 0;
        for (int i = 0; i < n; i++)
        {
            if(p[i]=='0') zp++;
            else op++;
            if(s[i]=='0') zs++;
            else os++;    
        }
        if((zp && op) || s==p) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}