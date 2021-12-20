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
        string a,b;
        cin>>a;
        cin>>b;
        bool isMatching = false;
        int once = 0;
        int zeroes = 0;
        string ans = "YES";
        for (int i = 0; i < a.length(); i++)
        {
            if(isMatching){
                if(a[i]!=b[i]) {
                    if(once!=zeroes){
                        ans = "NO";
                        break;
                    }else{
                        zeroes = 0;
                        once = 0;
                        isMatching = false;
                        
                    }
                }
                if(a[i]=='0') zeroes++;
                else once++;
            }else{
                if(a[i]==b[i]) {
                    if(once!=zeroes){
                        
                        ans = "NO";
                        break;
                    }else{
                        zeroes = 0;
                        once = 0;
                        isMatching = true;
                    }
                }
                if(a[i]=='0') zeroes++;
                else once++;
            }
        }
        if(!isMatching&&once!=zeroes) ans = "NO";
        cout<<ans<<endl;
    }
    return 0;
}