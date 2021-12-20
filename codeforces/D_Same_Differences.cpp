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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        for (int i = 0; i < n; i++) arr[i] -= i;
        map<int,int> m;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(m.find(arr[i])!=m.end()) ans+=m[arr[i]]++;
            else m[arr[i]]=1;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}