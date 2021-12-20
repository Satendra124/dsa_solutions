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
        int ones = 0;
        int zeros = 0;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(i==s.size() || s[i]!=s[i+1]){
                if(s[i]=='0') zeros++;
                else ones++;
            }
        }
        if(zeros>1) cout<<2<<endl;
        else cout<<zeros<<endl;
    }
    return 0;
}