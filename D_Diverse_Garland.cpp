#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;



int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i = 1; i < n; i++)
    {
        if(s[i-1]==s[i]||s[i+1]==s[i]){
            if(s[i-1]=='R'){
                if(s[i+1]=='R') s[i] = 'G';
                else if(s[i+1]=='G')s[i] = 'B';
                else s[i] = 'G';
            }else if(s[i-1]=='G'){
                if(s[i+1]=='R') s[i] = 'B';
                else if(s[i+1]=='G')s[i] = 'B';
                else s[i] = 'R';
            }else{
                if(s[i+1]=='R') s[i] = 'G';
                else if(s[i+1]=='G')s[i] = 'R';
                else s[i] = 'R';
            }
        }
        
    }
    cout<<s<<endl;
    return 0;
}