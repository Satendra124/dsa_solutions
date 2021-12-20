#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int pos = -1;
bool nextIsPalindrome(string& s){
    pos = -1;
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n/2; i++)
    {
        if(s[i]!=s[n-i-1]) {
            cnt++;
            pos = n-i-1;
            if(s[i]=='0') pos = i;
        }
    }
    if(cnt==1) return true;
    else return false;
}
void makeNextPalindrome(string& s){
    if(pos==-1){
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='0') {
                s[i] = '1';
                return;
            }
        }
        return;
    }
    s[pos] = '1';
    pos = -1;
}
bool is_plaindrome(string& s){
    int n = s.length();
    for (int i = 0; i < n/2; i++)
    {
        if(s[i]!=s[n-i-1]) {
            return false;
        }
    }
    return true;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        int n;
        cin>>n;
        cin>>s;
        // no of rounds will be number of zeros
        int zeros = 0;
        for(char c:s) if(c=='0') zeros++;
        int cost[2] = {0,0};
        bool move = false;
        bool lastRev = false;
        while (zeros)
        {
            bool nex = nextIsPalindrome(s);
            bool isPlaindrome  = is_plaindrome(s);
            if((nex||lastRev||isPlaindrome)&&!((zeros==1)&&!isPlaindrome&&!lastRev)) {
                makeNextPalindrome(s);
                zeros--;
                cost[move]++;
                lastRev = false;
            }
            else {
                reverse(s.begin(),s.end());
                lastRev = true;
            }
            move = !move;
        }
        if(cost[0]>cost[1]) cout<<"BOB"<<endl;
        else if(cost[0]==cost[1]) cout<<"DRAW"<<endl;
        else cout<<"ALICE"<<endl;
    }
    return 0;
}