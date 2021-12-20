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
        int cur = arr[0];
        int height = 0;
        int pos = 1;
        queue<pair<int,int>> q;
        q.push({1,0});
        while (pos<n)
        {
            int cur = q.front().first;
            int t = q.front().second;
            q.pop();
            cur = 0;
            for (; pos < n; pos++)
            {
                if(cur<arr[pos]){
                    q.push({arr[pos],t+1});
                    cur = arr[pos];
                }else{
                    break;
                }
            }
            height = max(height,t);
        }
        cout<<height+1<<endl;
    }
    return 0;
}