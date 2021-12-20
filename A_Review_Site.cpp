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
        int u = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            if(temp==1||temp==3) u++;
        }
        cout<<u<<endl;

    }
    return 0;
}