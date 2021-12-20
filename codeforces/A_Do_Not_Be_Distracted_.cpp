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
        unordered_set<char> his;
        char last = '-';
        string ans = "YES";
        for (int i = 0; i < n; i++)
        {

            if(last!=s[i]){
                if(his.find(s[i])!=his.end()){
                    ans = "NO";
                }else{
                    his.insert(s[i]);
                }
            }
            last = s[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}