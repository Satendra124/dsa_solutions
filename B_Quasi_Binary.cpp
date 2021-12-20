#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int getMaxQBinNo(int n){
    string s = to_string(n);
    string f = string(s.length(),'x');
    char maxNo = '0';
    for (int i = 0; i < f.length(); i++)
    {
        if(s[i]=='0') f[i] = '0';
        else f[i] = '1';
    }
    return stoi(f);
}

int main()
{
    int n;
    cin>>n;
    vector<int> ans ;
    while (n)
    {
        int x = getMaxQBinNo(n);
        ans.push_back(x); 
        n -= x;
    }
    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}