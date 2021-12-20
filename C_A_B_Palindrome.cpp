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
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        int n = a+b;
        //first treat question mark which are forcing
        bool ansExist  =true;
        for (int i = 0; i < n; i++)
        {  
            if(s[i]=='0'){
                if(s[n-i-1]=='?' || s[n-i-1]=='0'){
                    s[n-i-1] = '0';
                }else{
                    ansExist = false;
                }
            }else if(s[i]=='1'){
                if(s[n-i-1]=='?' || s[n-i-1]=='1'){
                    s[n-i-1] = '1';
                }else{
                    ansExist = false;
                }
            }else{
                if(s[n-i-1]=='1'){
                    s[i] = '1';
                }else if(s[n-i-1]=='0'){
                    s[i] = '0';
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='1') b--;
            else if(s[i]=='0') a--;
        }
        if(a<0||b<0) {
            cout<<-1<<endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='?'){
                if(b>1) {
                    s[i] = s[n-i-1] = '1';
                    b-=2;
                }else if(s[i]==s[n-i-1] && b>0){
                    s[i] = '1';
                    b--;
                }
                else if(a>1) {
                    s[i] = s[n-i-1] = '0';
                    a-=2;
                }else if(s[i]==s[n-i-1] && a>0){
                    s[i] = '0';
                    a--;
                }
                else {
                    ansExist = false;
                    break;
                }
            }
        }
        if(!ansExist){
            cout<<-1<<endl;
            continue;
        }
        cout<<s<<endl;

    }
    return 0;
}