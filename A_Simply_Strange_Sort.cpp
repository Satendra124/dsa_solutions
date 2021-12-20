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
        int ans = -1;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<=n;i++){
            bool sorted = true;
            for(int j=0;j<n-1;j++){
                if(arr[j]>arr[j+1]) {
                    sorted = false;
                    break;
                }
            }
            if(sorted){
                ans = i;
                break;
            }else{
                int k = (i%2);
                for(int j=k;j<n-1;j+=2){
                    if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}