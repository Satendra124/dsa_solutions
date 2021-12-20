// #include <bits/stdc++.h>
// using namespace std;
// int mod = 1e9 + 7;
// #define fast                      \
//     ios_base::sync_with_stdio(0); \
//     cin.tie(0);                   \
//     cout.tie(0);
// typedef long long int ll;
// int main()
// {
//     fast;
//     ll n;
//     cin >> n;
//     ll firstRoot = -1;
//     for (ll i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             firstRoot = i;
//             break;
//         }
//     }
//     //cout << firstRoot << endl;
//     if (firstRoot == -1)
//         cout << n << endl;
//     else
//     {
//         double q = log(n) / log(firstRoot);

//         if (abs(q - (int)q) < 0.000000000000001)
//             cout << firstRoot << endl;
//         else
//             cout << 1 << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    set<long long int> s;
    long long int ans, n, i, res;
    cin >> n;
    res = n;
    if (n == 1)
    {
        cout << "1";
        return;
    }
    while (n % 2 == 0)
    {
        n = n / 2;
        s.insert(2);
        ans = 2;
    }
    for (i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            n = n / i;
            s.insert(i);
            ans = i;
        }
    }
    if (n > 2)
    {
        s.insert(n);
        ans = n;
    }
    if (s.size() > 1)
    {
        cout << "1";
        return;
    }

    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1, i;
    // cin>>t;
    for (i = 1; i <= t; i++)
    {
        solve();
        // cout<<"\n";
    }
    return 0;
}