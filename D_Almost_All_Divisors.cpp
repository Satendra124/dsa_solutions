#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;

void soe(vector<int> &primes, int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
}
int getcnt(int prime, int val)
{
    int ans = 0;
    while (val % prime == 0)
    {
        val /= prime;
        ans++;
    }
    return ans;
}
int main()
{
    fast;
    int t;
    cin >> t;
    vector<int> primes;
    soe(primes, 1e6);
    while (t--)
    {
        int n;
        cin >> n;
        int divs[n];
        for (int i = 0; i < n; i++)
        {
            cin >> divs[i];
        }
        int primeCnt[primes.size()];
        memset(primeCnt, 0, sizeof(primeCnt));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < primes.size(); j++)
            {
                primeCnt[j] = max(primeCnt[j], getcnt(primes[j], divs[i]));
            }
        }
        ll ans = 1;
        for (int i = 0; i < primes.size(); i++)
        {
            //cout << primeCnt[i] << " " << primes[i] << endl;
            if (primeCnt[i] > 0)
                ans *= pow(primes[i], primeCnt[i]);
        }
        bool present = false;
        for (int i = 0; i < n; i++)
        {
            if (ans == divs[i])
                present = true;
        }
        if (present)
        {
            for (int i = 0; i < primes.size(); i++)
            {
                if (primeCnt[i] > 0)
                {
                    ans *= primes[i];
                    primeCnt[i]++;
                    break;
                }
            }
        }
        int total = 1;
        for (int i = 0; i < primes.size(); i++)
        {
            total *= (primeCnt[i] + 1);
        }
        //cout << total << endl;
        if (total - 2 == n)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}