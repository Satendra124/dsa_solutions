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
        int same = 0;
        if(arr[0]==arr[1]){
            same = arr[0];
        }else{
            same = arr[2];
        }
        for (int i = 0; i < n; i++)
        {
            if(arr[i]!=same) {
                cout<<i+1<<endl;
                break;
            }
        }
        
    }
    return 0;
}