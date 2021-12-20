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
        int arr[2*n];
        for (int i = 0; i < 2*n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+2*n);
        for (int i = 0; i < n; i++)
        {
            cout<<arr[n+i]<<" "<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}