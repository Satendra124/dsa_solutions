#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int power(long long x, unsigned int y, int p)
{
    int res = 1;  
 
    x = x % p; 
  
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

void trasverse(map<int,int>& m1,bool visited1[],int cur){
    if(visited1[cur]) return;
    visited1[cur] = true;
    trasverse(m1,visited1,m1[cur]);
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        map<int,int> m1;
        int arr[n][2];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i][0];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i][1];
        }
        for (int i = 0; i < n; i++)
        {
            m1[arr[i][0]] = arr[i][1];
        }
        bool visited1[n+1];
        memset(visited1,false,sizeof(visited1));
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if(!visited1[arr[i][0]]){
                cnt++;
                trasverse(m1,visited1,arr[i][0]);
            }
        }
        //cout<<cnt<<endl;
        cout<<power(2,cnt,1000000007)<<endl;
        
    }
    return 0;
}