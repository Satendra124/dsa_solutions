#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

bool isDiv(string &num,int a){
    //check if num % a ==0
    //cout<<num<<endl;

    int cur = 0;
    for(int i=0;i<num.size();i++){
        
        if(cur!=0)
        cur = cur*10 + (num[i]-'0');
        else cur = (num[i]-'0');
       // cout<<"cur:"<<cur<<endl;
        if(cur>=a){
            if(cur%a==0){
                cur = 0;
            }else{
                cur =cur%a;
            }
        }else continue;
    }
    //cout<<" "<<endl;
    if(cur==0) return true;
    else return false;

}
string run(int& a){
    queue<string> q;
    q.push("1");
    while(!q.empty()){
        string cur = q.front();
        q.pop();
        if(cur.size()>21) return "-1";
        if(isDiv(cur,a)) return cur;
        else{
            q.push(cur+'0');
            q.push(cur+'1');
        }
    }
    return "-1";
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<run(n)<<endl;
    }
    return 0;
}