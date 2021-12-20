#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int ptr1=0,ptr2=(n-1)/2;
    vector<int> ans;
    while (ptr1<(n-1)/2||ptr2<n)
    {
        if(ptr2<n) ans.push_back(arr[ptr2]);
        if(ptr1<(n-1)/2) ans.push_back(arr[ptr1]);
        ptr1++;
        ptr2++;
    }
    int cnt = 0;
    for (int i = 1; i < n-1; i++)
    {
        if(ans[i]<ans[i-1]&&ans[i]<ans[i+1]) cnt++;
    }
    cout<<cnt<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}