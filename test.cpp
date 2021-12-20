#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

string getEquation(int n,int x[],int y[]){
    if(n<=1) return "0";
    //equation from first 2 points
    //(y-  y1)*m1 = (x-x1) * m2
    int m1 = (x[1]-x[0]);
    int m2 = (y[1]-y[0]);
    int y1 = y[0];
    int x1 = x[0];
    //check for all other points
    bool flag = false;
    for (int i = 2; i < n; i++)
    {
        if((y[i]-y1)*m1 != (x[i]-x1)*m2) flag = true;
    }
    if(flag) return "0";
    string ans = "";
    if(m2>0) ans.append(to_string(m2) + "x");
    else ans.append("-"+to_string(m2) + "x");
    if(m1>0) ans.append("-"+to_string(abs(m1)) + "y");
    else ans.append("+"+to_string(abs(m1)) + "y");
    int c = -x1*m2 + y1*m1;
    ans.push_back('=');
    ans.append(to_string(c));
    return ans;

}

int main()
{
    fast;
    int n;
    cin>>n;
    int x[n];
    int y[n];
    for (int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i];
    }
    cout<<getEquation(n,x,y)<<endl;
    return 0;
}