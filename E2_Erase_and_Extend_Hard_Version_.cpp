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
    char maxChar = s[0];
    for (int i = 0; i < n; i++)
    {
        if(s[i]>maxChar) {
            last = i;
            break;
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