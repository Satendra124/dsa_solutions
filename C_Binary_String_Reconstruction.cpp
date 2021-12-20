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
        int x;
        cin>>x;
        int n = s.length();
        string w =  string(n,'1');
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='0'){
                if(i<n-x){
                    w[i+x] = '0';
                }
                if(i>=x){
                    w[i-x] = '0';
                }
            }

        }
        //checking
        for (int i = 0; i < n; i++)
        {
            bool one = false;
            one = one || (i - x >= 0 && w[i - x] == '1');
            one = one || (i + x < n && w[i + x] == '1');
    
            if (s[i] != one + '0') {
                w = "-1";
                break;
            }
        }
        

        cout<<w<<endl;
        
    }
    return 0;
}