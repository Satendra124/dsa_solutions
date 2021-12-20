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
        string s;
        cin>>s;
        int ans = 0;
        int dif = 0;
        for (int i = 0; i < n-1; i++)
        {
            if(s[i]>'0') dif++;
            ans += s[i] - '0';
        }
        ans += dif;
        cout<<ans+s[n-1]-'0'<<endl;   
    }
    return 0;
}