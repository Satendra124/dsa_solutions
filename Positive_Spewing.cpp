#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

ll solve(int n,int k,vector<ll> arr){
    ll left[n];
    ll right[n];
    int i = 0;
    int last = 0;
    for (i = 0; i < n; i++)
    {
        if(arr[i]!=0) break;
    }
    i++;
    for ( i = 0; i < n; i++)
    {
        left[i] = last++;
        if(arr[i]!=0) last = 0;
    }
    for (i = 0; i < n; i++)
    {
        left[i] = last++;
        if(arr[i]!=0) break;
    }
    //left done
    i =0;
    last = 0;
    for (i = n-1; i >=0; i--)
    {
        if(arr[i]!=0) break;
    }
    i--;
    for ( i = n-1; i >=0; i--)
    {
        right[i] = last++;
        if(arr[i]!=0) last = 0;
    }
    for ( i = n-1; i >=0; i--)
    {
        right[i] = last++;
        if(arr[i]!=0) last = 0;
    }
    //right done
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=0){
            left[i] = min(1ll,left[i]);
            right[i] = min(1ll,right[i]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        ans += max(0ll,k - min(left[i],right[i]+2));
        ans += max(0ll,k - min(left[i]+2,right[i]));
    }
    return ans;
}
ll slow(int n,int k,vector<ll> arr){
    ll ans = 0;
    for (int j = 0; j < k; j++)
    {
        vector<ll> arr2 = arr;
        for (int i = 0; i < n; i++)
        {
            if(i>0 && arr[i]!=0) arr2[i-1]++;
            if(i<n-1 && arr[i]!=0) arr2[i+1]++;
            
        }
        if(arr[n-1]!=0) arr2[0]++; 
        if(arr[0]!=0) arr2[n-1]++;
        arr = arr2;
    }
    for (int i = 0; i < n; i++)
    {
        ans += arr[i];
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
        int n,k;
        //cin>>n>>k;
        n = 1+ rand()%10000;
        k = rand()%10000;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            //cin>>arr[i];
            arr[i] = rand()%100000000;
        }
        ll f = solve(n,k,arr);
        ll s = slow(n,k,arr);
        if(s!=f){
            cout<<"NO"<<n<<" "<<k<<" "<<endl;
            cout<<s<<" "<<f<<endl;
            for (int i = 0; i < n; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}