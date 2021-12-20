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
        sort(arr,arr+n);
        vector<int> mins(n,INT_MAX);
        for (int i = 1; i < n; i++)
        {
            mins[i] = min(abs(arr[i] - arr[i-1]),mins[i-1]);
        }
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]>mins[i]){
                ans = i;
                break;
            } 
        }
        cout<<ans<<endl;
    }
    return 0;
}