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
        int diff[n-1];
        for (int i = 0; i < n-1; i++)
        {
            diff[i] = arr[i+1] - arr[i];
        }
        int minDif = INT_MAX;
        int minDifI = 0;
        for (int i = 0; i < n-1; i++)
        {
            if(minDif>diff[i]){
                minDif = diff[i];
                minDifI = i;
            }
        }
        //cout<<arr[minDifI+1]<<" ";

        if(n==2){
            cout<<arr[0]<<" "<<arr[1]<<endl;
            continue;
        }

        for (int i = minDifI+1; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        for (int i = 0; i < minDifI+1; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}