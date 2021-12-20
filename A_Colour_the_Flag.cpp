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
        int n,m;
        cin>>n>>m;
        char arr[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>arr[i][j];
            }
        }
        //only two possiblity 
        //WRWRWRWRWRWR
        //odd places w even R
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if((i+j)%2==0 && arr[i][j]=='W') flag = true;
                if((i+j)%2!=0 && arr[i][j]=='R') flag = true;
            }
        }
        if(!flag){
            cout<<"YES"<<endl;
            //odd me W even me R
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if((i+j)%2==0) cout<<"R";
                    if((i+j)%2!=0) cout<<"W";
                }
                cout<<endl;
            }
            continue;
        }
        flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if((i+j)%2==0 && arr[i][j]=='R') flag = true;
                if((i+j)%2!=0 && arr[i][j]=='W') flag = true;
            }
        }
        if(!flag){
            cout<<"YES"<<endl;
            //odd me W even me R
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if((i+j)%2==0) cout<<"W";
                    if((i+j)%2!=0) cout<<"R";
                }
                cout<<endl;
            }
            continue;
        }
        else cout<<"NO"<<endl;
        
    }
    return 0;
}