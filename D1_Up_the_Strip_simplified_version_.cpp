#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;

int dp[200000];
int dp2[200000];
int solve(ll n, ll &m)
{
    if (dp[n] != -1)
        return dp[n];
    if (n == 1)
        return 1;
    if (n < 1)
        return 0;
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[n - i] != -1)
            ans = (ans + dp[n - i]) % m;
        else
            ans = (ans + solve(n - i, m)) % m;
    }
    for (int i = 2; i <= n; i++)
    {
        if (dp[n / i] != -1)
            ans = (ans + dp[n / i]) % m;
        else
            ans = (ans + solve(n / i, m)) % m;
    }
    return dp[n] = ans % m;
}
int fst(ll n, ll m)
{

    ll sum = 0;
    ll dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    sum = 3;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = sum;
        vector<ll> v;
        for (int j = 1; j * 1ll * j <= i; j++)
        {
            v.push_back(j);
            v.push_back(i / j);
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for (int j = 0; j < v.size() - 1; j++)
        {
            dp[i] += dp[v[j]] * 1ll * (i / v[j] - i / v[j + 1]);
            dp[i] %= m;
        }

        sum += dp[i];
        sum %= m;
    }

    return dp[n];
}

int main()
{
    fast;
    ll n, m;
    cin >> n >> m;
    cout << fst(n, m) << endl;
    // for (int i = 2; i <= 200000; i++)
    // {
    //     n = i;
    //     memset(dp, -1, sizeof(dp));
    //     m = 12323432;
    //     if (solve(n, m) != fst(n, m))
    //     {
    //         cout << n << " " << m << " " << solve(n, m) << " " << fst(n, m) << endl;
    //     }
    // }
    return 0;
}