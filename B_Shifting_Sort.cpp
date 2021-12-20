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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        vector<int> srr = arr;
        sort(srr.begin(),srr.end());
        //cout<<n<<endl;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            int req = srr[i];
            int idx = -1;
            if(req==arr[i]) continue;
            for (int j = i; j < n; j++)
            {
                if(req==arr[j]){
                    idx = j;
                }
            }
            arr.erase(arr.begin()+idx);
            arr.insert(arr.begin()+i,req);
            ans.push_back({i+1,idx+1,idx-i});
            //cout<<i+1<<" "<<idx+1<<" "<<1<<endl;
            // for (int i = 0; i < n; i++)
            // {
            //     cout<<arr[i]<<" ";
            // }
            // cout<<endl;
        }
        cout<<ans.size()<<endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
        }
        
        
    }
    return 0;
}