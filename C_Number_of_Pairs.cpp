#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int bsm(int arr[],int n,int target){
    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l<=r){
        int mid  = l+ (r-l)/2;
        if(arr[mid]>=target){
            ans = mid;
            r =  mid-1;
        }else l = mid+1;
    }
    return ans;

}

int bsM(int arr[],int n,int target){
    int l = 0;
    int r = n-1;
    int ans = -1;
    while(l<=r){
        int mid  = l+ (r-l)/2;
        if(arr[mid]<=target){
            ans = mid;
            l = mid+1;
        }else r =  mid-1;
    }
    return ans;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int li = bsm(arr,n,l-arr[i]);
            int ri = bsM(arr,n,r-arr[i]);
            //cout<<li<<" "<<ri<<endl;
            if(!(li==-1 || ri==-1) && ri>=li){
                //no number to make pair with
                if(i>=li && i<=ri) cnt += ri - li;
                else cnt += ri - li+1;
            }
        }
        cout<<cnt/2<<endl;
        
    }
    return 0;
}