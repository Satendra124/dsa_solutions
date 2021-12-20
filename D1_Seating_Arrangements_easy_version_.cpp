#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int solve(vector<int>& v,int val){
    //cout<<"v: ";
    //for(int i:v){
    //    cout<<i<<" ";
    //}
    //cout<<endl;
    int pos = -1;
    int l =0;
    int r = v.size()-1;
    while (l<=r)
    {
        int mid = l + (r-l)/2;
        if(v[mid]<val){
            pos = mid;
            l = mid+1;
        }else r = mid-1;
    }
    //cout<<"pos"<<pos<<endl;
    v.insert(v.begin()+pos+1,val);
    return pos+1;
    
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[m];
        for (int i = 0; i < m; i++)
        {
            cin>>arr[i];
        }
        vector<int> v;
        int incon = 0;
        for (int i = 0; i < m; i++)
        {
            int a = solve(v,arr[i]);
            //cout<<a<<" "<<arr[i]<<endl;
            incon +=a;
        }
        cout<<incon<<endl;
        
        
    }
    return 0;
}