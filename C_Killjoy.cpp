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
        int n,x;
        cin>>n>>x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int num = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]!=x){
                num++;
                sum += arr[i] - x;
            }
        }
        if(num!=0){
            if(sum==0||num!=n) cout<<1<<endl;
            else cout<<2<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}