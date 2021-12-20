    #include <bits/stdc++.h>
    using namespace std;
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<vector<int>> pos(2);
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                pos[x & 1].push_back(i);
            }
            int odd = pos[1].size(), even = pos[0].size();
            if (abs(odd - even) >= 2) {
                cout << -1 << "\n";
                continue;
            }
            auto cal = [](vector<int>& pos) {
                int res = 0, cur = 0;
                for (auto i : pos) {
                    res += abs(cur - i);
                    cur += 2;
                }
                return res;
            };
            if (odd == even) {
                cout << min(cal(pos[0]), cal(pos[1])) << "\n";
            } else {
                cout << cal(pos[odd > even]) << "\n";
            }
        }
        return 0;
    }