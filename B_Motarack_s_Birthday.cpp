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
        for (int i = 0; i < n; i++) cin>>arr[i];
        int l=-1,h=-1;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]==-1){
                if(i>0){
                    if(i<n-1){
                        l =min(min(arr[i-1],arr[i+1]),l);
                        h = max(max(arr[i-1],arr[i+1]),h);
                    }else{
                        l = min(arr[i-1],l);
                        h = max(arr[i-1],h);
                    }
                }else{
                    l = min(arr[i+1],l);
                    h = max(arr[i+1],h);
                }
            }
        }
        cout<<(l+h)/2<<endl;
        
        
    }
    return 0;
}