#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n;
    cin>>n;
    int arr[n];
    ll avg = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        avg += arr[i];
    }
    ll sum = avg;
    avg /= n;
    //array values can be avg or avg+1 based on situation 
    ll avg1 = avg;
    ll avg2 = avg;
    if(sum%n) avg2++;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<avg1){
            ans+=avg1-arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>avg2){
            ans++;
        }
    }
    
    cout<<ans<<endl;


    return 0;
}