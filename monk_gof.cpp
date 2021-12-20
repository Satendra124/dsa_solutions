#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    queue< pair<int,int> > q1;
    queue< pair<int,int> > q2;
    queue< pair<int,int> > q3;
    queue< pair<int,int> > q4;

    while (t--)
    {
        char e;
        cin>>e;
        if(e=='E'){
            int s,r;
            cin>>s>>r;
            if(q1.empty()||q1.front().first==s){
                q1.push(pair<int,int>(s,r));
            }else if(q2.empty()||q2.front().first==s){
                q2.push(pair<int,int>(s,r));
            }else if(q3.empty()||q3.front().first==s){
                q3.push(pair<int,int>(s,r));
            }else{
                q4.push(pair<int,int>(s,r));
            }
        }else{
            if(!q1.empty()){
                cout<<q1.front().first<<" "<<q1.front().second<<endl;
            }
            else if(!q2.empty()){
                cout<<q2.front().first<<" "<<q2.front().second<<endl;
            }
            else if(!q3.empty()){
                cout<<q3.front().first<<" "<<q3.front().second<<endl;
            }
            else{
                cout<<q4.front().first<<" "<<q4.front().second<<endl;
            }
        }

    }
    return 0;
}