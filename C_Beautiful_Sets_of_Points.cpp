#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    cout<<min(n,m)+1<<endl;
    for (int i = 0; i <= min(n,m); i++)
    {
        cout<<i<<" "<<min(n,m)-i<<endl;
    }
    return 0;
}