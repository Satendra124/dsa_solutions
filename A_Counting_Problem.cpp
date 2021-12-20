#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int solve(int n,int b[],bool filled){
    if(n==0) return 0;
    if(b[n-1]==b[n])
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int b[n-1];
        for (int i = 0; i < n-1; i++)
        {
            cin>>b[i];
        }
        cout<<solve(n,b)<<endl;
    }
    return 0;
}