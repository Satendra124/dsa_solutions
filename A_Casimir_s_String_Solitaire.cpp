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
        string s;
        int a=0,b=0,c=0;
        cin>>s;
        for(char& ch:s){
            if(ch=='A') a++;
            else if(ch=='B') b++;
            else c++;
        }
        //cout<<a<<b<<c<<endl;
        if((a==0&&b==c)|| (c==0 && a==b)||(a==0 && b==0 && c==0) || a+c==b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}