#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int main()
{
    fast;
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int last = n;
    bool br = false;
    for (int i = 0; (i < n) &&!br ; i++)
    {
        for (int j = 0,p=i+1; j <= i && p<n; j++,p++)
        {
            if(s[p]<s[j]) break;
            else if(s[p]>s[j] || p==n-1) {
                last = i+1;
                br = true;
                break;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        int j = i;
        if(j>=last) j = j%last;
        cout<<s[j];
    }
    cout<<endl;
    return 0;
}