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
        cin>>s;
        string finalS = "";
        bool ans = false;
        int n = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            if(s[n-i-1]!='a'&&!ans){
                finalS.push_back('a');
                finalS.push_back(s[i]);
                ans = true;
            }else{
                finalS.push_back(s[i]);
            }
        }
        if(ans){
            cout<<"YES"<<endl;
            cout<<finalS<<endl;
        }else cout<<"NO"<<endl;
        
    }
    return 0;
}