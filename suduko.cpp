#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int colorful(int A);
    vector<vector<char>> boardAns;
    void solve(vector<vector<char>> board,int i,int j){
        //cout<<i<<" "<<j<<endl;
        if(board[i][j]!='.'){
            if(i<8){
                if(j<8) {
                    solve(board,i,j+1);
                    return;
                }else{
                    solve(board,i+1,0);
                    return;
                }
            }else{
                if(j<8) {
                    solve(board,i,j+1);
                    return;
                }else{
                    boardAns = board;
                    return;
                }
            }
        }
        //cout<<"solving:"<<i<<" "<<j<<endl;
        char possible[] = {'1','2','3','4','5','6','7','8','9'};
        //horizontal
        for(int p=0;p<9;p++){
            if(board[i][p]!='.'){
                possible[board[i][p]-'0'-1] = '-';
            }
            if(board[p][j]!='.'){
                possible[board[p][j]-'0'-1] = '-';
            }
        }
        int starti,endi,startj,endj;
        if(i>=0 && i<=2){
            starti = 0;
            endi = 2;
        }
        else if(i>2 && i<=5){
            starti = 3;
            endi = 5;
        }
        else if(i>5 && i<=8){
            starti = 6;
            endi = 8;
        }
        if(j>=0 && j<=2){
            startj = 0;
            endj = 2;
        }
        else if(j>2 && j<=5){
            startj = 3;
            endj = 5;
        }
        else if(j>5 && j<=8){
            startj = 6;
            endj = 8;
        }
        
        for(int p=starti;p<endi;p++){
            for(int k = startj;k<endj;k++){
                if(board[p][k]!='.'){
                    possible[board[p][k]-'0'-1] = '-';
                }
            }
        }
        for(int p = 0;p<9;p++){
            if(possible[p]!='-'){
                board[i][j] = possible[p];
                solve(board,i,j);
            }
        }
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        boardAns = board;
        solve(board,0,0);
        board = boardAns;
    }
};


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }
    Solution().solveSudoku(a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}


int Solution::colorful(int A) {
    map<int,bool> ispersent;
    string a = to_string(A);
    int n = a.size();
    int pervProd = a[0];
    int last = 1;
    for(int len=1;len<=a.length();len++){
        last = pervProd;
        last = last*a[len-1];
        pervProd = last;
        if(ispersent[last]) return 0;
        else ispersent[last] = true;
        for (int i = len; i < n-len-1; i++)
        {
            last *= a[i]/a[i-len];
            if(ispersent[last]) return 0;
            else ispersent[last] = true;
        }
        
    }
    
}
