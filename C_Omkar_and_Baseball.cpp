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
        for (auto &ai : a) cin >> ai;
        int s = 0;
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != i + 1) {
                if (first) s = 1;
                if (!first) {
                    s = 2;
                }
            } else {
                if (s == 1) {
                    first = false;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}