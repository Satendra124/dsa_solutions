// #include <bits/stdc++.h>
// using namespace std;
// int mod = 1e9+7;
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// typedef unsigned long long int ll;
// const int nax = 100001;
// const ll inf = 1e15;
// map<ll,map<ll,ll>> graph;
// ll dist[nax];
// ll back[nax];
// int n,m;

// ll getMaxInPath(){
//     //find path
//     //get the max
//     vector<int> path;
//     int cur = n;
//     ll m = 0;
//     while(cur!=1){
//         int nex = back[cur];
//         m = max(m,graph[nex][cur]);
//         cur = nex;
//     }
//     return m;
// }
// bool visited[nax];
// ll dj(){
//     priority_queue<pair<ll,ll>> q;
//     q.push({0,1});
//     while(!q.empty()){
//         int cur = q.top().second;q.pop();
//         if(visited[cur]) continue;
//         visited[cur] = true;
//         for(pair<ll,ll> a:graph[cur]){
//             ll next = a.first,w = a.second;
//             if(dist[next]>dist[cur]+w){
//                 dist[next] = dist[cur]+w;
//                 back[next] = cur;
//                 q.push({-dist[next],next});
//             }
//         }
//     }
//     return dist[n];
// }

// int main()
// {
//     fast;
//     cin>>n>>m;
//     dist[1] = 0;
//     for (int i = 2; i <= n; i++)
//     {
//         dist[i] = inf;
//     }
    
//     for (int i = 0; i < m; i++)
//     {
//         ll u,v,p;
//         cin>>u>>v>>p;
//         if(graph[u][v]) graph[u][v] = min(graph[u][v],p);
//         else graph[u][v] = p;
//     }
//     ll ans = dj();

//     ll m = getMaxInPath();

//     ans -= m;
//     m /=2;
//     ans += m;
//     cout<<ans<<endl;
    
//     return 0;
// }


#include <iostream>

#include <vector>

#include <queue>

#include <algorithm>

using namespace std;


int main()

{

	int n, m;

	cin >> n >> m;

	//in[i] contains flights from city i

	//out[i] contains flights to city i

	vector<pair<int, int>> in[100000], out[100000];

	for (int i = 0; i < m; i++)

	{

		int a, b, c;

		cin >> a >> b >> c;

		out[a - 1].push_back({b - 1, c});

		in[b - 1].push_back({a - 1, c});

	}

	priority_queue<pair<long long, int>> q; //(-price, city)

	bool visited[100000]{};


	//find the price to go from city 1 to all other cities

	long long dist1[100000];

	fill(dist1, dist1 + n, 1e18);

	dist1[0] = 0;

	q.push({0, 0});

	while (!q.empty())

	{

		int a = q.top().second;

		q.pop();

		if (visited[a]) continue;

		visited[a] = true;

		for (auto i : out[a])

		{

			int b = i.first, w = i.second;

			if (dist1[a] + w < dist1[b])

			{

				dist1[b] = dist1[a] + w;

				q.push({-dist1[b], b});

			}

		}

	}


	//find the price to go from each city to city n

	long long distn[100000];

	fill(distn, distn + n, 1e18);

	fill(visited, visited + n, false);

	distn[n - 1] = 0;

	q.push({0, n - 1});

	while (!q.empty())

	{

		int a = q.top().second;

		q.pop();

		if (visited[a]) continue;

		visited[a] = true;

		for (auto i : in[a])

		{

			int b = i.first, w = i.second;

			if (distn[a] + w < distn[b])

			{

				distn[b] = distn[a] + w;

				q.push({-distn[b], b});

			}

		}

	}


	//take the minimum cost after using the coupon over all pairs of cities

	long long cost = dist1[n - 1];

	for (int a = 0; a < n; a++)

	{

		for (auto i : out[a])

		{

			int b = i.first, w = i.second;

			cost = min(cost, dist1[a] + distn[b] + w / 2);

		}

	}

	cout << cost << endl;

	return 0;

}