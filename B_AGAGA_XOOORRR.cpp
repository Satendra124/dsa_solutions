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
        for (int i = 0; i < n; i++) cin>>arr[i];
        int n1 = 0;
        for (int i = 0; i < n-1; i++) n1 ^= arr[i];
        int n2 = 0;
        for (int i = 1; i < n; i++) n2 ^= arr[i];
        int n3 = 0;
        for (int i = 0; i < n; i++) n3 ^= arr[i];
        //cout<<n1<<" "<<n2<<" "<<n3<<endl;
        if(n1==n2 || n2==n3 || n1==n3) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}