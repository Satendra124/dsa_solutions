#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
struct my_comparator
{
    bool operator()(std::vector<int> const& a, std::vector<int> const& b) const
    {
        assert(a.size() == 3);
        assert(b.size() == 3); 
        if(a[0]!=b[0])
        return a[0] > b[0];
        else if(a[1]!=b[1]) return a[1]>b[1];
        else return a[2]>b[2];
    }
};


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
        priority_queue<vector<int>,vector<vector<int>>,my_comparator> q;
        q.push({-n+1,0,n-1});
        int i = 1;
        while(!q.empty()){
            vector<int> cur = q.top();
            q.pop();
            if(cur[0]>0) continue;
            int mid = (cur[1]+cur[2])/2;
            arr[mid] = i;
            i++;
            q.push({mid+1-cur[2],mid+1,cur[2]});
            q.push({cur[1]-mid+1,cur[1],mid-1});
        }
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}