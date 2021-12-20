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
        int o = 0,e=0;
        for (int i = 0; i < 2*n; i++)
        {
            int temp;
            cin>>temp;
            if(temp%2) o++;
            else e++;
        }
        if(o==n && e==n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}