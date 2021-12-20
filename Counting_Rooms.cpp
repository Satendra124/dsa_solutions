#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

vector<vector<int>> floors;
char house[1000][1000];
bool visited[1000][1000];
int n,m;
void travel(int i,int j){
    //in this we travel all cells linked to this
    if(i==n||j==m||i<0||j<0) return;
    if(house[i][j]=='#') return;
    if(visited[i][j]) return;

    visited[i][j] = true;
    travel(i+1,j);
    travel(i,j+1);
    travel(i-1,j);
    travel(i,j-1);
}

int main()
{
    fast;
    cin>>n>>m;
    //house = vector<vector<char>>(n,vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>house[i][j];
            if(house[i][j]=='.') floors.push_back({i,j});
        }
    }
    //floor contains list of all points which are floor not walls
    int rooms = 0;
    for (int i = 0; i < floors.size(); i++)
    {
        if(!visited[floors[i][0]][floors[i][1]]){
            travel(floors[i][0],floors[i][1]);
            rooms++;
        }
    }
    cout<<rooms<<endl;
    return 0;
}