//wont pass

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
        int a[n+1];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        string ans = "Yes";
        for (int i = 0; i < n-1; i++)
        {
            if(a[i]<a[i+1] && a[i]+1!=a[i+1]){
                ans = "No";
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}