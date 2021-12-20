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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        cout<<3*n<<endl;
        for (int i = 1; i <= n; i += 2) {
                cout<<"2 "<<i<<" "<<i+1<<endl;
                cout<<"1 "<<i<<" "<<i+1<<endl;
                cout<<"2 "<<i<<" "<<i+1<<endl;
                cout<<"1 "<<i<<" "<<i+1<<endl;
                cout<<"2 "<<i<<" "<<i+1<<endl;
                cout<<"1 "<<i<<" "<<i+1<<endl;
        }
    }
    return 0;
}