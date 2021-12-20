#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    string s;
    cin>>s;
    int l=0,u=0;
    for(char& c:s){
        if(c<='z' &&c>='a') l++;
        else u++;
    }
    if(u>l) {
        for(char& c:s){
            if(c<='z' &&c>='a') cout<<char('A'+c-'a');
            else cout<<c;
        }
    }else{
        for(char& c:s){
            if(c<='z' &&c>='a') cout<<c;
            else cout<<char('a' +c- 'A');
        }
    }
    return 0;
}