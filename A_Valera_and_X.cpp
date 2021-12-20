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
    char arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    char l1 = arr[0][0];
    char l2 = arr[0][1];
    bool ans = true;
    if (l1 == l2)
        ans = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == j || i + j == n - 1) && arr[i][j] != l1)
                ans = false;
            else if ((i != j && i + j != n - 1) && arr[i][j] != l2)
                ans = false;
        }
    }
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}