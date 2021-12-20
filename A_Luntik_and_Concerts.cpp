#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef unsigned long long int ll;
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if ((a + b * 2 + c * 3) % 2 == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}