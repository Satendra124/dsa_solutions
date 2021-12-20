#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;

int findMod(int num, map<int, bool> &visited)
{
    ll l = 0;
    ll r = num - 1;
    ll ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (visited[mid])
        {
            r = mid - 1;
        }
        else
        {
            ans = mid;
            l = mid + 1;
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
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back({temp, i});
        }
        sort(arr.begin(), arr.end(), greater<vector<int>>());
        ll a[n];
        map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            int mod = findMod(arr[i][0], visited);
            if (mod == -1)
            {
                a[arr[i][1]] = arr[i][0];
            }
            else
            {
                a[arr[i][1]] = arr[i][0] + mod;
                visited[mod] = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}