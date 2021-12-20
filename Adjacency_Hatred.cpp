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
        vector<int> o;
        vector<int> e;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            if(arr[i]%2) o.push_back(arr[i]);
            else e.push_back(arr[i]);
            //arr[i] = rand()%10;
        }
        if(o.size()==0 || e.size()==0) cout<<-1<<endl;
        else{
            for (int i = 0; i < o.size(); i++)
            {
                cout<<o[i]<<" ";
            }
            for (int i = 0; i < e.size(); i++)
            {
                cout<<e[i]<<" ";
            }
            cout<<endl;
            
        }
       
    }
    return 0;
}