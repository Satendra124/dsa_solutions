#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n,q;
    cin>>n>>q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int indexApper[n];
    for (int i = 0; i < n; i++)
    {
        indexApper[i] = 0;
    }
    
    for (int i = 0; i < q; i++)
    {
        int start,end;
        cin>>start>>end;
        for (int j = start-1; j < end; j++) indexApper[j]++;
    }
    sort(indexApper,indexApper+n);
    sort(arr,arr+n);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        //cout<<arr[i]<<" "<<indexApper[i]<<endl;
        s+= arr[i]*indexApper[i];
    }
    cout<<s<<endl;
    
    return 0;
}