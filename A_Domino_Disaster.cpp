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
        for(char& c:s){
            if(c=='U') cout<<'D';
            else if(c=='D') cout<<'U';
            else cout<<c;
        }
        cout<<endl;
    }
    return 0;
}