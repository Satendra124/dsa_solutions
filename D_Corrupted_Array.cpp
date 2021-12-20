#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int checkIfSum(ll arr[],int n,int sumi){
    ll total = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if(i!=sumi){
            total += arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(i!=sumi && arr[sumi]==total-arr[i]){
            ans = i;
            break;
        }
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
        int n;
        cin>>n;
        n+=2;
        ll arr[n];
        for (int i = 0; i < n; i++) cin>>arr[i];
        ll maxN = INT_MIN;
        ll maxNi=-1,secondMaxi=-1;
        for (int i = 0; i < n; i++)
        {
            if(maxN<arr[i]){
                secondMaxi = maxNi;
                maxN = arr[i];
                maxNi = i;
            }
        }
       // cout<<maxNi<<" "<<secondMaxi<<endl;
        int one =maxNi ==-1?-1: checkIfSum(arr,n,maxNi);
        int two =secondMaxi ==-1?-1: checkIfSum(arr,n,secondMaxi);
        if(one!=-1){
            for (int i = 0; i < n; i++)
            {
                if(i!=maxNi && i!=one){
                    cout<<arr[i]<<" ";
                }
            }
        }else if(two !=-1){
            for (int i = 0; i < n; i++)
            {
                if(i!=secondMaxi && i!=two){
                    cout<<arr[i]<<" ";
                }
            }
        }else{
            cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}