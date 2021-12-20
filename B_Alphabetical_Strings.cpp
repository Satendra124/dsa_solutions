#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

bool check(string s,int f,int l,int cnt){
    if(f<0 && l==s.size()) return true;
    if(f>=0 && s[f]==cnt+'a') return check(s,f-1,l,cnt+1);
    else if(l<s.size() && s[l]==cnt+'a') return check(s,f,l+1,cnt+1);
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
        int a = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='a') a = i;
        }
        
        if(a!=-1 && check(s,a-1,a+1,1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}