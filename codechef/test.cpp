#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
ll mod = 1e9+7;

int analyse(char b[3][3]){
    char board[3][3];
        int x=0,o=0,bl=0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j]=b[i][j];
                if(board[i][j]=='X') x++;
                else if(board[i][j]=='O') o++;
                else bl++;
            }
        }
        if(x==o || x-1==o){
            int winCombs = 0;
            set<char> winners;
            int h=0,v=0,d=0;
            //horizontal and vertical
            for (int i = 0; i < 3; i++)
            {
                if((board[i][0]!='_')&& (board[i][0]==board[i][1])&&(board[i][1]==board[i][2])) {
                    winners.insert(board[i][0]);
                    h++;
                    winCombs++;
                }
                if((board[0][i]!='_')&& (board[0][i]==board[1][i])&&(board[1][i]==board[2][i])) {
                    winners.insert(board[0][i]);
                    winCombs++;
                    v++;
                }
            }
            //diagonal
            if((board[1][1]!='_')&& (board[0][0]==board[1][1])&&(board[1][1]==board[2][2])) {
                winners.insert(board[1][1]);
                winCombs++;
                d++;
            }
            if((board[1][1]!='_')&& (board[2][0]==board[1][1])&&(board[1][1]==board[0][2])) {
                winners.insert(board[1][1]);
                winCombs++;
                d++;
            }
            if(winCombs==1) {
                if(winners.find('O')!=winners.end() && x>o) return 3;
                else if(winners.find('X')!=winners.end()&&x==o) return 3;
                else return 1;
            }
            else if(winCombs==2){
                if(winners.size()==1){
                    if(v<2&&h<2) return 1;
                    if(d==2) return 1;
                    else return 3;
                }else return 3;
            }
            else if(winCombs==0) {
                if(bl==0) return 1;
                else return 2;
            }
            else return 3;
        }else{
            return 3;
        }
}
void iter(char board[3][3],char turn,int moves){
    int res = analyse(board);
    if(res==1) return;
    if(res==3){
        cout<<"ERROR"<<endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(moves==0) return;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j]=='_'){
                board[i][j] = turn;
                if(turn=='X'){
                    iter(board,'O',moves--);
                }else{
                    iter(board,'X',moves--);
                }
                board[i][j] = '_';
            }
        }
        
    }
    
}

int main()
{
    char board[3][3] = {
        {'_','_','_'},
        {'_','_','_'},
        {'_','_','_'}
    };
    int bl = 9;
    iter(board,'X',bl);
    
    return 0;
}