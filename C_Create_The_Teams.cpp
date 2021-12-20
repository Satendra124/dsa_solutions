#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n,greater<int>());
        int ans = 0,cur =1;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]*cur>=x) {
                ans++;
                cur = 0;
            }
            cur ++;
        }
        cout<<ans<<endl;
    }
    return 0;
}