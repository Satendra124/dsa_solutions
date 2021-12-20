#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        k--;
        if (m < n - 1 || m > n * (n - 1) / 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (m == n - 1 && k > n - 1)
                cout << "YES" << endl;
            else if (k < 2)
                cout << "NO" << endl;
            else
            {
                if (k >= 3 || (m == n * (n - 1) / 2) && k >= 2)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}