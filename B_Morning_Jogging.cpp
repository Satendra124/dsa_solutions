#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int binarySearch(vector<int> v,int target){
    int l = 0;
    int r = v.size();
    while(l<=r){
        int mid = (l+r)/2;
        if(v[mid]>target) r = mid-1;
        else if(v[mid]==target) return mid;
        else l = mid+1;
    }
    return -1;
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
        vector<vector<int>> arr(n,vector<int>(m));
        vector<int> arr2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>arr[i][j];
                arr2.push_back(arr[i][j]);
            }
            sort(arr[i].begin(),arr[i].end());
        }
        sort(arr2.begin(),arr2.end());
        int smallest[m];
        for (int i = 0; i < m; i++)
        {
            smallest[i] = arr2[i];
        }
        vector<vector<int>> out(n,vector<int>(m,-1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(smallest[j]!=-1){
                    int bs = binarySearch(arr[i],smallest[j]);
                    if(bs!=-1){
                        out[i][j] = arr[i][bs];
                        arr[i][bs] = -1;
                        //cout<<" "<<smallest[j]<<endl;
                        smallest[j] = -1;
                    }
                }
                
            }
            sort(arr[i].begin(),arr[i].end(),greater<int>());
            int k = 0;
            for (int j = 0; j < m; j++)
            {
                if(out[i][j]==-1){
                    out[i][j] = arr[i][k++];
                }
            }
            
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout<<out[i][j]<<" ";
            }
            cout<<endl;
        }
        
        
    }
    return 0;
}