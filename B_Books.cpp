#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int binarySearch(int arr[],int n,int start,int target){
    int end = n-1;
    int res = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]>=target){
            res = mid;
            start = mid +1;
        }else{
            end = mid-1;
        }
    }
    return res;
}

int main()
{
    fast;
    int n,t;
    cin>>n>>t;
    int arr[n];
    for (int i = 0; i < n; i++) cin>>arr[i];
    for(int i=n-2;i>=0;i--) arr[i] += arr[i+1];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>t){
            int sub = binarySearch(arr,n,i+1,arr[i]-t);
            ans = max(ans,sub-i);
        }else{
            ans = max(ans,n-i);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}