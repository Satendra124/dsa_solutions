#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int cols;
int rows;
int rec(int col,int row){
    if(col==cols&&row==rows) return 1;
    if(col>cols||row>rows) return 0;
    return rec(col+1,row) + rec(col,row+1);
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        //cols  = x2 - x1 +1;
        cout<<abs(x2-x1)*abs(y2-y1) +  1<<endl;
    }
    return 0;
}