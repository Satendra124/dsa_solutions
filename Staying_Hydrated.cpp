#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;

int find_distance_x(int x, vector<vector<int>> &objs)
{
    int ans = 0;
    for (vector<int> &ob : objs)
    {
        if (!(ob[0] <= x && ob[2] >= x))
        {
            ans += min(abs(ob[2] - x), abs(ob[0] - x));
        }
    }
    return ans;
}

int find_distance_y(int y, vector<vector<int>> &objs)
{
    int ans = 0;
    for (vector<int> &ob : objs)
    {
        if (!(ob[1] <= y && ob[3] >= y))
        {
            ans += min(abs(ob[3] - y), abs(ob[1] - y));
        }
    }
    return ans;
}

int main()
{
    fast;
    int t;
    cin >> t;
    int T = t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> objs;
        int maxX = 0, maxY = 0;
        for (int i = 0; i < k; i++)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            maxX = max(maxX, x1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y1);
            maxY = max(maxY, y2);
            objs.push_back({x1, y1, x2, y2});
        }
        int l = 0;
        int r = maxX;
        int x = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int cur_dist = find_distance_x(mid, objs);
            int next_dist = find_distance_x(mid + 1, objs);
            int prev_dist = find_distance_x(mid - 1, objs);

            if (cur_dist == 0 || (next_dist >= cur_dist && prev_dist > cur_dist))
            {
                x = mid;
                break;
            }

            else if (prev_dist > cur_dist)
            {
                l = mid + 1;
            }
            else if (next_dist >= cur_dist)
            {
                r = mid - 1;
            }else{
                
            }
        }
        l = 0;
        r = maxY;
        int y = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int cur_dist = find_distance_y(mid, objs);
            int next_dist = find_distance_y(mid + 1, objs);
            int prev_dist = find_distance_y(mid - 1, objs);
            if (cur_dist == 0 || (next_dist > cur_dist && prev_dist > cur_dist))
            {
                y = mid;
                break;
            }
            else if (next_dist > cur_dist)
            {
                r = mid - 1;
            }
            else if (prev_dist > cur_dist)
            {
                l = mid + 1;
            }
        }
        cout << "Case #" << T - t << ": " << x << " " << y << endl;
    }
    return 0;
}