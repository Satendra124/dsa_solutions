#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int d;
    cin>>d;
    int t = d;
    int x;
    cin>>x;
    while (t--)
    {
        string ans = "";
        int r=0,s=0,p=0;
        int w,e;
        cin>>w>>e;
        for (int i = 0; i < 60; i++)
        {
            if(r>s && r>p){
                //going to output P
                ans.push_back('S');
                s++;
            }else if(s>r && s>p){
                //going to output R
                ans.push_back('P');
                p++;
            }else if(p>r && p>s){
                //going to output S
                ans.push_back('R');
                r++;
            }else if(s==p && r<s){
                ans.push_back('P');
                p++;
            }else if(s==r && p<r){
                ans.push_back('P');
                p++;
            }else{
                ans.push_back('S');
                s++;
            }
        }
        cout<<"Case #"<<d - t<<": "<<ans<<endl;
        
    }
    return 0;
}