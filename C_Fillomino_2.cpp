#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,-1));
    for (int i = 0; i < n; i++)
    {
        cin>>board[i][i];
    }
    for (int i = 0; i < n; i++)
    {
        // at i,i we need to make board[i][i] blocks fill
        int req = board[i][i];
        int col = i;
        while (col<n&&req>0)
        {
            int row = i;
            //we go to the left
            board[col][row] = board[i][i];
            req--;
            while (row>0&&(board[col][row-1]==-1)&&req>0) {
                req--;
                board[col][row-1] = board[i][i];
                row--;
            }
            col++;   
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if(board[i][j]!=-1)
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    return 0;
}