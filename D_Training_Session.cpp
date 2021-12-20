#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;

ll cnt(vector<int> v)
{
    ll ans = 0;
    int n = v.size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += v[i];
    }

    for (int i = 0; i < v.size(); i++)
    {
        //3
        if (v[i] >= 3)
        {
            ans += v[i] * (v[i] - 1) * (v[i] - 2) / 6;
        }
        //2
        if (v[i] >= 2)
        {
            ans += (v[i] * (v[i] - 1) / 2) * (total - v[i]);
        }
    }
    return ans;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        map<int, ll> sub;
        map<int, ll> dif;
        int arr[n][2];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][0] >> arr[i][1];
        }
        for (int i = 0; i < n; i++)
        {
            sub[arr[i][0]]++;
            dif[arr[i][1]]++;
        }
        ll ways = 0;
        for (int i = 0; i < n; i++)
        {
            ways += (sub[arr[i][0]] - 1) * (dif[arr[i][1]] - 1);
        }

        ll total = n * (n - 1) * (n - 2) / 6;
        cout << total - ways << endl;
    }
    return 0;
}