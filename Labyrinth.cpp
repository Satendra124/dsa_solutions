// #include <bits/stdc++.h>
// using namespace std;
// int mod = 1e9+7;
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// typedef long long int ll;
// int n,m;
// char lab[1000][1000];
// int A[2];
// bool visited[1000][1000];
// vector<char> finalpath;
// vector<char> pathfinder(){
//     queue<pair<vector<int>,vector<char>>> q;
//     q.push({{A[0],A[1]},vector<char>()});
//     while(!q.empty()){
//         vector<int> point = q.front().first;
//         vector<char> path = q.front().second;
//         q.pop();
//         if(point[0]==n||point[1]==m||point[0]<0||point[1]<0) continue;
//         else if(visited[point[0]][point[1]]) continue;
//         else if(lab[point[0]][point[1]]=='.'||lab[point[0]][point[1]]=='A'){
//             path.push_back('U');
//             q.push({{point[0]-1,point[1]},path});
//             path.pop_back();

//             path.push_back('D');
//             q.push({{point[0]+1,point[1]},path});
//             path.pop_back();

//             path.push_back('R');
//             q.push({{point[0],point[1]+1},path});
//             path.pop_back();

//             path.push_back('L');
//             q.push({{point[0],point[1]-1},path});
//             path.pop_back();
//         }else if(lab[point[0]][point[1]]=='B') {
//             return path;
//         }
//         visited[point[0]][point[1]] = true;
//     }
//     return finalpath;
// }

// int main()
// {
//     fast;
//     cin>>n>>m;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < m; j++){
//             cin>>lab[i][j];
//             if(lab[i][j]=='A'){
//                 A[0] = i;
//                 A[1] = j;
//             }
//         }
//     }
//     finalpath = pathfinder();
//     if(finalpath.size()>0){
//         cout<<"YES"<<endl;
//         cout<<finalpath.size()<<endl;
//         for (int i = 0; i < finalpath.size(); i++)
//         {
//             cout<<finalpath[i];
//         }
//     }else cout<<"NO"<<endl;
//     return 0;
// }



#include <bits/stdc++.h>


using namespace std;


#define ii pair<int, int>

#define f first

#define s second

#define mp make_pair


int n, m;

char A[1000][1000];

bool vis[1000][1000];


// previousStep stores the previous direction that we moved in to arrive that this cell

int previousStep[1000][1000];


// 0 = up, 1 = right, 2 = down, 3 = left

int dx[4] = { -1, 0, 1, 0 };

int dy[4] = { 0, 1, 0, -1 };

string stepDir = "URDL";


int main() {

	cin >> n >> m;


	queue<ii> q;

	ii begin, end;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			cin >> A[i][j];

			if (A[i][j] == 'A') {

				begin = mp(i, j);

			} else if (A[i][j] == 'B') {

				end = mp(i, j);

			}

		}

	}


	q.push(begin);

	vis[begin.f][begin.s] = true;


	while (!q.empty()) {

		ii u = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {

			ii v = mp(u.f + dx[i], u.s + dy[i]);

			if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;

			if (A[v.f][v.s] == '#') continue;

			if (vis[v.f][v.s]) continue;

			vis[v.f][v.s] = true;

			previousStep[v.f][v.s] = i;

			q.push(v);

		}

	}


	if (vis[end.f][end.s]) {

		cout << "YES" << endl;

		vector<int> steps;

		while (end != begin) {

			int p = previousStep[end.f][end.s];

			steps.push_back(p);

			// undo the previous step to get back to the previous square

			// Notice how we subtract dx/dy, whereas we added dx/dy before

			end = mp(end.f - dx[p], end.s - dy[p]);

		}

		reverse(steps.begin(), steps.end());


		cout << steps.size() << endl;

		for (char c : steps) {

			cout << stepDir[c];

		}

		cout << endl;

	} else {

		cout << "NO" << endl;

	}


	return 0;

}