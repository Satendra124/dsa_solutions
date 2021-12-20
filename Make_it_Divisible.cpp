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
        int a;
        cin>>a;
        if(a==1) cout<<3;
        else{
            cout<<1;
            for (int i = 1; i < a-1; i++)
            {
                cout<<0;
            }
            cout<<5;
        }
        cout<<endl;
    }
    return 0;
}