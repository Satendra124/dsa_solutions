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
        vector<int> farr;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]%2==0){
                farr.push_back(arr[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(arr[i]%2){
                farr.push_back(arr[i]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if(__gcd(farr[i],2*farr[j])>1) cnt++;
            } 
        }
        cout<<cnt<<endl;

    }
    return 0;
}