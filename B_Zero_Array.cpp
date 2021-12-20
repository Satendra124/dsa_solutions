//TLE
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
    for (int i = 0; i < n; i++) cin>>arr[i];
    int M = *max_element(arr,arr+n);
    ll sum = 0;
    ll ssum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        
    }
    
    
    return 0;
}