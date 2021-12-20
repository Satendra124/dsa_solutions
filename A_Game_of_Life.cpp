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
        string arr;
        cin>>arr;
        string ans = arr;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]=='1') continue;
            for (int j = i-1,k=i+1,iter = 0; (j>=0||k<n)&&iter<x; j--,k++,++iter)
            {
                if((j>=0)&&(k<=n)&& arr[j]==arr[k]&&arr[j]=='1') break;
                else if(((j>=0)&&arr[j]=='1')||((k<n)&&arr[k]=='1')) {
                    ans[i] = '1';
                    break;
                }
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;
}