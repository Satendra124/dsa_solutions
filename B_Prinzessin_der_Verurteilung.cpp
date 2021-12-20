#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

void next(string& s){
    int n = s.length();
    for (int i = n - 1; i >= 0; i--)
    {
        if(s[i]!='z'){
            s[i]++;
            return;
        }else{
            s[i] = 'a';
        }
    }
    s.push_back('a');
    
}
bool isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
 
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return true;
    }
    return false;
}
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
        string cur = "a";
        bool flag = true;
        while(flag){
            if(!isSubstring(cur,s)){
                cout<<cur<<endl;
                flag = false;
            }
            next(cur);
        }

    }
    return 0;
}