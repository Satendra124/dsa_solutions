#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

bool checkIfPartialSumExist(int arr[],int n,int sum,int notConsider){
    int start = 0;
    int end = 
    
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
        int arr[n];
        for (int i = 0; i < n; i++) cin>>arr[i];
        int ans= 0;
        sort(arr,arr+n);
        for (int i = 0; i < n; i++)
        {
            ans += checkIfPartialSumExist(arr,n,arr[i],i);
        }
        cout<<ans<<endl;
        
    }
    return 0;
}