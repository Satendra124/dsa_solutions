#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;

int gret(int a, vector<int> &arr)
{
    int l = 0;
    int r = arr.size() - 1;
    int n = r + 1;
    int ans = n;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] > a)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return n - ans;
}

int main()
{
    fast;
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<int> diff;
    for (int i = 0; i < n; i++)
    {
        diff.push_back(a[i] - b[i]);
    }
    sort(diff.begin(), diff.end());
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += gret(b[i] - a[i], diff);
        if (a[i] > b[i])
            ans--;
        //cout << ans << endl;
    }
    cout << ans / 2 << endl;
    return 0;
}