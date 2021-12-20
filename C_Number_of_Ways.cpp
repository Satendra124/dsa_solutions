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
    int n;
    cin >> n;
    int arr[n];
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }
    if (total % 3 != 0)
        cout << 0 << endl;
    else
    {
        int sum = total / 3;
        vector<int> parts;
        int t_sum = 0;
        for (int i = 0; i < n; i++)
        {
            t_sum += arr[i];
            if (t_sum == sum)
            {
                parts.push_back(i);
                t_sum = 0;
            }
        }
        int zeros = 0;
    }
    return 0;
}