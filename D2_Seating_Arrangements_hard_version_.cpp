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
        vector<int> arr;
        vector<pair<int,int>> sortedArr;
        for (int i = 0; i < n*m; i++)
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
            sortedArr.push_back({temp,i});
        }
        sort(sortedArr.begin(),sortedArr.end());
        map<int,int> row;
        for (int i = 0; i < n*m; i++)
        {
            row[sortedArr[i].second] = i/m;
        }
        vector<vector<int>> vv(n);
        int incon = 0;
        for (int i = 0; i < n*m; i++)
        {
            int a = solve(vv[row[i]],arr[i]);
            //cout<<a<<" "<<arr[i]<<endl;
            incon +=a;
        }
        cout<<incon<<endl;
        
        
        
    }
    return 0;
}