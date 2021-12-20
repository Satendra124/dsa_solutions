#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

string nextBin(string curBin){
    int n = curBin.length();
    for (int i = n - 1; i >= 0; i--)
    {
        if(curBin[i]=='0') {
            curBin[i]='1';
            return curBin;
        }else{
            curBin[i] = '0';
        }
    }
    curBin.insert(0,"1");
    return curBin;
    
}

bool ifIsSubstring(string str,string subStr){
    int i = 0;
    int j = 0;
    while(i<str.length()&&j<subStr.length()){
        if(str[i]==subStr[j]){
            i++;
            j++;
        }else i++;
    }
    if(j==subStr.length()) return true;
    else return false;
}




int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        //string cur = "0";
        // while(ifIsSubstring(s,cur)){
        //     cur = nextBin(cur);
        // }
        // cout<<cur<<endl;
    }
    return 0;
}