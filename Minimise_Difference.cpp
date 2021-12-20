#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long int ll;
int find_val(vector<int> &c, map<int, vector<int>> &graph)
{
    int ans = 0;
    int n = c.size();
    for (int i = 1; i <= n; i++)
    {
        int chota_padosi = 0;
        for (int j : graph[i])
        {
            if (c[i] > c[j])
                chota_padosi++;
        }
        ans = max(ans, chota_padosi);
    }
    return ans;
}
void tester(vector<int> arr, vector<int> left, map<int, vector<int>> &graph, int &fin_ans)
{
    if (left.size() == 0)
    {
        arr.insert(arr.begin(), 0);
        int res = find_val(arr, graph);
        fin_ans = min(fin_ans, res);
        // cout << "TESTING FOR: ";
        // for (int i : arr)
        //     cout << i << " ";
        // cout << endl;
        // cout << "RESULT: " << res << endl;
    }
    else
    {
        for (int i = 0; i < left.size(); i++)
        {
            arr.push_back(left[i]);
            vector<int> leftB = left;
            leftB.erase(leftB.begin() + i);
            tester(arr, leftB, graph, fin_ans);
            arr.pop_back();
        }
    }
}
map<int, vector<int>> randGraph(int vertices)
{
    map<int, vector<int>> graph;
    bool visited[vertices + 1][vertices + 1];
    memset(visited, false, sizeof(visited));
    for (int i = 1; i < vertices; i++)
    {
        int e = rand() % (vertices);
        for (int j = 0; j < e; j++)
        {
            int other = i + 1 + rand() % (vertices - i);
            if (visited[i][other])
                continue;
            graph[i].push_back(other);
            graph[other].push_back(i);
            visited[i][other] = true;
        }
    }
    return graph;
}

int algo(map<int, vector<int>> &graph, int n)
{
    vector<vector<int>> padosi(n);
    for (int i = 0; i < n; i++)
    {
        int nei = graph[i + 1].size();
        padosi[i] = {nei, i + 1};
    }
    sort(padosi.begin(), padosi.end(), greater<vector<int>>());
    vector<int> c(n + 1);
    for (int i = 0; i < n; i++)
    {
        c[padosi[i][1]] = i + 1;
    }
    int ans = find_val(c, graph);

    // cout << ans << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << c[i] << " ";
    // }
    // cout << endl;
    return ans;
}
int main()
{
    fast;
    int t = 10000;
    // cin >> t;
    while (t--)
    {
        int n, m;
        //cin >> n >> m;
        n = 1 + rand() % 5;
        map<int, vector<int>> graph;
        // for (int i = 0; i < m; i++)
        // {
        //     int u, v;
        //     cin >> u >> v;
        //     graph[u].push_back(v);
        //     graph[v].push_back(u);
        // }
        graph = randGraph(n);

        //TEST

        int min_by_test = INT_MAX;
        vector<int> left;
        for (int i = 1; i <= n; i++)
            left.push_back(i);

        tester({}, left, graph, min_by_test);
        //cout << "TEST: " << min_by_test << endl;
        //TEST

        int ans = algo(graph, n);

        if (ans != min_by_test)
        {
            cout << "PROBLEM" << endl;
            cout << ans << " " << min_by_test << endl;
            for (int i = 1; i <= n; i++)
            {

                cout << i << ": ";
                for (int j : graph[i])
                    cout << j << " ";
                cout << endl;
            }
        }
        //cout << "COMPLETE" << endl;
    }
    return 0;
}