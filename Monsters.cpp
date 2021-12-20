// #include <bits/stdc++.h>
// using namespace std;
// int mod = 1e9+7;
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// typedef long long int ll;

// int n,m;
// char naksa[1001][1001];
// vector<vector<int>> monsters(1001,vector<int>(1001,INT_MAX));
// vector<vector<bool>> visitedM(1001,vector<bool>(1001,false));
// vector<char> ans;
// bool ansGot = false;
// //bool visitedM[1001][1001];
// void mTransverse(int i,int j){
//     // if(i==n||j==m||i<0||j<0) return;
//     // if(visitedM[i][j]) return;
//     // if(naksa[i][j]=='#') return;
//     // else if((monsters[i][j]==-1 )|| (monsters[i][j]>steps)) monsters[i][j] = steps;
//     // visitedM[i][j] = true;
//     // mTransverse(i+1,j,steps+1);
//     // mTransverse(i,j+1,steps+1);
//     // mTransverse(i-1,j,steps+1);
//     // mTransverse(i,j-1,steps+1);

//     //bfs needed
//     queue<pair<pair<int,int>,int>> q;
//     q.push({{i,j},0});
//     while(!q.empty()){
//         pair<pair<int,int>,int> c = q.front();q.pop();
//         pair<int,int> cur = c.first;
//         int steps = c.second;
//         if(cur.first==n||cur.second==m||cur.first<0||cur.second<0) continue;
//         if(visitedM[cur.first][cur.second]) continue;
//         if(naksa[cur.first][cur.second]=='#') continue;
//         else if((monsters[cur.first][cur.second]==-1 )|| (monsters[cur.first][cur.second]>steps)) monsters[cur.first][cur.second] = steps;
//         visitedM[cur.first][cur.second]  = true;
//         q.push({{cur.first+1,cur.second},steps+1});
//         q.push({{cur.first-1,cur.second},steps+1});
//         q.push({{cur.first,cur.second+1},steps+1});
//         q.push({{cur.first,cur.second-1},steps+1});
//     }

// }
// void ATransverse(int i,int j,int steps,vector<char> path){
//     //cout<<i<<" "<<j<<endl;
//     if(ansGot) return;
//     if(((i==n)||(j==m)||(i==-1)||(j==-1))){
//         return;
//     }
//     if(visitedM[i][j]) return;
//     if(naksa[i][j]=='#') return;
//     else if(monsters[i][j]<=steps) return;
//     if(((naksa[i][j]=='.')||(naksa[i][j]=='A'))&&((i==n-1)||(j==m-1)||(i==0)||(j==0))){
//         ans = path;
//         ansGot = true;
//         return;
//     }
//     visitedM[i][j] = true;
//     path.push_back('D');
//     ATransverse(i+1,j,steps+1,path);
//     path.pop_back();
//     path.push_back('R');
//     ATransverse(i,j+1,steps+1,path);
//     path.pop_back();
//     path.push_back('U');
//     ATransverse(i-1,j,steps+1,path);
//     path.pop_back();
//     path.push_back('L');
//     ATransverse(i,j-1,steps+1,path);
//     path.pop_back();
// }

// int main()
// {
//     fast;
//     cin>>n>>m;
//     vector<pair<int,int>> mCords;
//     pair<int,int> a;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin>>naksa[i][j];
//             if(naksa[i][j]=='M') mCords.push_back({i,j});
//             else if(naksa[i][j]=='A') a = {i,j};
//         }
//     }
//     for(pair<int,int> cords:mCords){
//         mTransverse(cords.first,cords.second);
//         visitedM = vector<vector<bool>>(1001,vector<bool>(1001,false));
//     }
//     // for (int i = 0; i < n; i++)
//     // {
//     //     for (int j = 0; j < m; j++)
//     //     {
//     //         cout<<monsters[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
    
//     // start path of a
//     ATransverse(a.first,a.second,0,{});
//     if(ansGot){
//         cout<<"YES"<<endl;
//         cout<<ans.size()<<endl;
//         for (int i = 0; i < ans.size(); i++)
//         {
//             cout<<ans[i];
//         }
        
//     }else cout<<"NO"<<endl;
//     return 0;
// }


#include <iostream>

#include <vector>

#include <queue>

#include <climits>

#include <cstring>

#include <algorithm>

#define pii pair<int, int>

#define mn 1005

using namespace std;


int N, M;

queue<pii> q;

int paths[mn][mn];

pii from[mn][mn];

int oo = INT_MAX;

pii A;

string ans;

bool possible = false;


void retrace(pii node){  // retrace from final node, adding direction from previous node to a string. This string will be backwards but will be reversed before output.

	pii origin = from[node.first][node.second];

	if(origin ==  pii(0,0)) return;

	if(origin.first == node.first+1) ans.push_back('U');

	if(origin.first == node.first-1) ans.push_back('D');

	if(origin.second == node.second+1) ans.push_back('L');

	if(origin.second==node.second-1) ans.push_back('R');

	retrace(origin);


}

void check(pii origin, pii dest){ // check if the considered destination may be traveled to

	int pl = paths[origin.first][origin.second];

	if(pl+1<paths[dest.first][dest.second]){

		paths[dest.first][dest.second]  = pl+1;

		q.push(dest);

		from[dest.first][dest.second] = origin;

	}

}

bool mora = false; // false if bfs for monsters, true if bfs for A

void bfs(){

	while(!q.empty()){

		pii loc = q.front(), next; q.pop();

		next = loc; next.first++; check(loc, next); // go through adjacent locations

		next = loc; next.first--; check(loc, next);

		next = loc; next.second++; check(loc, next);

		next = loc; next.second--; check(loc, next);

		if(mora && (loc.first == 1 || loc.second == 1 || loc.first == N || loc.second == M)){

			cout << "YES" << endl;

			cout << paths[loc.first][loc.second] << endl;

			retrace(loc);

			possible = true;

			return;

		}

	}

}

int main() {

	cin >> N >> M;

	for(int i = 1; i <= N; i++){

		string s;

		cin >> s;

		for(int j = 1; j <= M; j++){

			paths[i][j] = oo;

			if(s[j-1] == '#') paths[i][j] = 0;

			if(s[j-1] == 'M') {q.push(pii(i,j)); paths[i][j]  = 0;}

			if(s[j-1] == 'A') {A.first = i; A.second = j;}

		}

	}

	bfs(); // monster bfs

	mora = true; // change next bfs to A bfs

	from[A.first][A.second] = pii(0,0); // give the retrace a terminating location

	paths[A.first][A.second] = 0; q.push(A); // get ready for next bfs

	bfs(); // bfs with A

	if(possible){

		reverse(ans.begin(), ans.end());

		cout << ans << endl;

	}

	else cout << "NO" << endl;

}