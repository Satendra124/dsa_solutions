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
        int first = s.size();
        bool c = false;
        char cs[2] = {'B','R'};
        for (int i = 0; i < s.size(); i++)
         {
            if(s[i]!='?') {
                first = i;
                c =(s[i]-'B');
                break;
            }
        }
        if(first==s.size()){
            bool l = false;
            for (int i = 0; i < s.size(); i++)
            {
                if(l)
                    cout<<"R";
                else cout<<"B";
                l = !l;
            }
        }else{
            if(first%2==0){
                for (int i = 0; i < first; i++)
                {
                    cout<<cs[c];
                    c = !c;
                }
            }else{
                for (int i = 0; i < first; i++)
                {
                    cout<<cs[!c];
                    c = !c;
                }
            }
            char last = s[first];
            for (int i = first; i < s.size(); i++)
            {
                if(s[i]=='?'){
                    cout<<cs[!(last-'B')];
                    last = cs[!(last-'B')];
                }
                else{
                     cout<<s[i];
                     last = s[i];
                }
            }
        }
        cout<<endl;
    }
    return 0;
}