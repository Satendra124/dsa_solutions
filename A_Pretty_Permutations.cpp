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
        if(n%2==0){
            for(int i=1;i<=n;i+=2){
                cout<<i+1<<" "<<i<<" ";
            }
            cout<<endl;
        }else{
            for (int i = 1; i < n-3; i+=2)
            {
                cout<<i+1<<" "<<i<<" ";
            }
            cout<<n<<" "<<n-2<<" "<<n-1<<endl;
            
        }
    }
    return 0;
}