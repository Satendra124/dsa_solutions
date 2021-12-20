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
        int M = INT_MIN;
        int m = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            M = max(temp,M);
            m = min(temp,m); 
        }
        if(m<0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            cout<<M+1<<endl;
            for (int i = 0; i <= M; i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        
        
    }
    return 0;
}