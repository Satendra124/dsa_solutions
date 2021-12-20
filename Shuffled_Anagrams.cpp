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
    int p  = t;
    while (t--)
    {
        string s;
        cin>>s;
        string ini = s;
        vector<vector<int>> let(26);
        for(int i=0;i<s.size();i++){
            let[s[i]-'a'].push_back(i);
        }
        int p1_l = 0,p1_i = 0;
        int p2_l = 1,p2_i = 0;
        while(p1_l<26 && p2_l<26){
            if(let[p1_l].size()==p1_i){
                p1_l =  p2_l;
                p1_i = p2_i;
                p2_l++;
                p2_i =0 ;
                continue;
            }
            if(let[p2_l].size()==p2_i){
                p2_l++;
                p2_i = 0;
                continue;
            }
            swap(s[let[p1_l][p1_i]],s[let[p2_l][p2_i]]);
            p1_i++;
            p2_i++;
        }
        bool ans =true;
        for(int i=0;i<s.size();i++){
            if(ini[i]==s[i]) ans = false;
        }
        if(ans) cout<<"Case #"<<p - t+1<<" "<<s<<endl;
        else cout<<"Case #"<<t<<" "<<"IMPOSSIBLE"<<endl;
    } 
    return 0;
}