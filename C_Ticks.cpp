#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
char grid[20][20];
bool visited[20][20];
bool check(int i,int j,int k,int n,int m){
    int len = 0;
    int I=i,J=j;
    while(--i>=0 && --j>=0){
        if(grid[i][j]!='*' && len<k) return false;
        len++;
    }

    if(len<k) return false;
    len = 0;
    i =I,j=J;
    while(--i<n && ++j<m){
        if(grid[i][j]!='*' && len<k) return false;
        len++;
    }
    if(len<k) return false;
    return true;
}
void update(int i,int j,int n,int m){
    visited[i][j] = true;
    int I=i,J=j;
    while(--i>=0 && --j>=0){
        if(grid[i][j]=='*') visited[i][j]=true;
        else break;
    }
    i =I,j=J;
    while(--i<n && ++j<m){
        if(grid[i][j]=='*') visited[i][j] = true;
        else break;
    }
}
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        memset(visited,false,sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>grid[i][j];
            }
        }
        bool ans = true;
        for (int i = n-1; i >=k; i--)
        {
            for (int j = m-1; j >=k; j--)
            {
                if(grid[i][j]=='.') continue;
                if(check(i,j,k,n,m)){
                    update(i,j,n,m);
                }else if(!visited[i][j]){
                    //cout<<"SDA"<<endl;
                    ans = false;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]=='*' && !visited[i][j]) ans = false;
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}