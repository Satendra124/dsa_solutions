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
        bool sorted = true;
        for (int i = 1; i < n; i++)
        {
            if(arr[i]<arr[i-1]) {
                sorted = false;
                break;
            }
        }
        
        int min = *min_element(arr,arr+n);
        int max = *max_element(arr,arr+n);
        if(sorted) cout<<0<<endl;
        else if(min==arr[0]||max==arr[n-1]){
            cout<<1<<endl;
        }else if(min==arr[n-1]&&max==arr[0]) cout<<3<<endl ;
        else cout<<2<<endl;
    }
    return 0;
}