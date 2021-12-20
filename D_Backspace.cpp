#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

bool lo(int a,int b,string& s,string& t){
    if(b==t.length() && a==s.length()) return true;
    if(a>=s.length()) return false;
    if(b==t.length()) return lo(a+2,b,s,t);
    if(s[a]==t[b]) return lo(a+1,b+1,s,t);
    else return lo(a+2,b,s,t);
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        string t;
        cin>>s;
        cin>>t;
        if(lo(0,0,s,t)||lo(1,0,s,t)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}