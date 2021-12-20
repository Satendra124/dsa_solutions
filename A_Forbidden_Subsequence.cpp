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
        string s,a;
        cin>>s>>a;
        int cnts[26];
        memset(cnts,0,sizeof(cnts));
        for(char &c:s) cnts[c-'a']++;
        reverse(a.begin(),a.end());
        for(char &c:a){
            while(cnts[c-'a']--){
                cout<<c;
            }
        }
        cout<<endl;
    }
    

    return 0;
}