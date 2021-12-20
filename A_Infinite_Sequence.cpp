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
    int a, b, c;
    cin >> a >> b >> c;
    if ((c == 0 && a == b) || ((c != 0) && ((b - a) % c == 0) && (b - a) / c >= 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}