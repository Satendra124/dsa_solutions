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
        int n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long double avg = 0.0;
        for (int i = 0; i < n; i++)
        {
            avg += arr[i];
        }
        avg = avg / (n * 1.0);
        //cout << avg << endl;
        map<ll, ll> cnt;
        for (int i = 0; i < n; i++)
        {
            cnt[arr[i]]++;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            long double req = 2 * avg - (arr[i] * 1.0);
            if (abs(req - int(req)) < 0.00000000000000000000000001)
            {

                ans = ans + cnt[int(req)];
                if (req == arr[i])
                    ans--;
            }
        }
        cout << ans / 2 << endl;
    }
    return 0;
}