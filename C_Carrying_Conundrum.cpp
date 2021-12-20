#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int possible_ways(int num){
    if(num>18) return 0;
    int mid = num/2;
    int mid_big = num - mid;
    int ans = min(9,num) - mid_big + 1;
    ans *= 2;
    if(mid==mid_big) ans--;
    //cout<<num<<" "<<ans<<endl;
    return ans;
}


int solve(string s,int cur,int last_2_rem,int last_rem){
    if(cur<0) {
        if(last_2_rem==0 && last_rem==0)
            return 1;
        else return 0;
    }
    int digit = s[cur] - '0';
    digit-=last_2_rem;
    if(digit<0) return 0;
    int m1 = solve(s,cur-1,last_rem,0);
    int m2 = solve(s,cur-1,last_rem,1);
    int a1 = possible_ways(digit);
    int a2 = possible_ways(digit + 10);
    //cout<<cur<<" "<<m1<<" "<<m2<<" "<<a1<<" "<<a2<<endl;
    //cout<<a1<<" "<<m1<<" "<<a2<<" "<<m2<<endl;
    return a1*m1+a2*m2;
}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        cout<<solve(s,s.length()-1,0,0)-2<<endl;
    }
    return 0;
}