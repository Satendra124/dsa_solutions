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
        int arr[11];
        memset(arr,0,sizeof(arr));
        for (int i = 0; i < 4; i++)
        {
            int temp;
            cin>>temp;
            arr[temp]++;
        }
        int cnt = 0;
        int ans = 2;

        for (int i = 0; i < 11; i++)
        {
            if(arr[i]==4) {
                ans = 0;
                break;
            }else if(arr[i]==3){
                ans = 1;
                break;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}