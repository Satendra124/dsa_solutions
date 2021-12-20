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
        string ans = "";
        for(char& c:s){
            int dig = c - '0';
            for(int i=dig;i>=2;i--){
                if(i==2) ans.append("2");
                else if(i==3) {
                    ans.append("3");
                    break;
                }
                else if(i==4) ans.append("22");
                else if(i==5) {
                    ans.append("5");
                    break;
                }
                else if(i==6) ans.append("3");
                else if(i==7) {
                    ans.append("7");
                    break;
                }
                else if(i==8) ans.append("222");
                else if(i==9) ans.append("332"),i--;
            }
        }
        sort(ans.begin(),ans.end(),greater<char>());
        cout<<ans<<endl;
    }
    return 0;
}