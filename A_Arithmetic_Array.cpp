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
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            sum+=temp;
        }
        if(n==sum) cout<<0<<endl;
        else if(n-sum>0) cout<<1<<endl;
        else{
            cout<<sum-n<<endl;
        }
    }
    return 0;
}