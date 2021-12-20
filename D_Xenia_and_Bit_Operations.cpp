#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;

void build(int seg[], int arr[], int n, int m)
{
    int j = 0;
    bool op = true;
    for (int i = 0; i < n; i += 2, j++)
    {
        seg[j] = arr[i] | arr[i + 1];
    }
    n /= 2;
    while (n > 1)
    {
        for (int i = 0; i < n; i += 2, j++)
        {
            if (op)
                seg[j] = seg[(j - 1) / 2] ^ seg[(j - 1) / 2 + 1];
            else
                seg[j] = seg[(j - 1) / 2] | seg[(j - 1) / 2 + 1];
        }
        op = !op;
        n /= 2;
    }
}
void update(int seg[], int arr[], int p, int b, int n, int m)
{
    int x = 0;
    arr[p] = b;
    for (int k = 0; k < m; k++)
    {
        cout << seg[k] << " ";
    }
    cout << endl;
    if (p % 2 == 0)
    {
        seg[p / 2] = arr[p] | arr[p + 1];
    }
    else
    {
        seg[p / 2] = arr[p] | arr[p - 1];
    }

    for (int k = 0; k < m; k++)
    {
        cout << seg[k] << " ";
    }
    cout << endl;
    n /= 2;
    p /= 2;
    x = n + p / 2;
    bool op = true;

    while (n > 1)
    {
        for (int k = 0; k < m; k++)
        {
            cout << seg[k] << " ";
        }
        cout << endl;
        if (!op)
        {
            seg[(x)] = seg[(x) / 2] | seg[(x) / 2 - 1];
        }
        else
        {
            seg[(x)] = seg[(x) / 2] ^ seg[(x) / 2 - 1];
        }
        for (int k = 0; k < m; k++)
        {
            cout << seg[k] << " ";
        }
        cout << endl;
        n /= 2;
        x += n;
        op = !op;
    }
}
int main()
{
    fast;
    int n, m;
    cin >> n >> m;
    int n_ele = pow(2, n);
    int arr[n_ele];
    for (int i = 0; i < n_ele; i++)
    {
        cin >> arr[i];
    }
    int seg_cnt = (n - 1) * n_ele + 1;
    int seg[seg_cnt];
    build(seg, arr, n_ele, seg_cnt);
    while (m--)
    {
        int p, b;
        cin >> p >> b;
        update(seg, arr, p - 1, b, n_ele, seg_cnt);
        cout << seg[seg_cnt - 1] << endl;
    }
    return 0;
}