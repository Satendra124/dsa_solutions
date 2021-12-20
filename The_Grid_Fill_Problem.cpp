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
        if(n%2==0){
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout<<-1<<" ";
                }
                cout<<endl;
            }
        }else{
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(i!=j) cout<<-1<<" ";
                    else cout<<1<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}