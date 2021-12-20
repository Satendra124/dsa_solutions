#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int costForGoodString(string s,char c){
    if (s.size() == 1) {
		return s[0] != c;
	}
    int mid = s.size() / 2;
	int cntl = costForGoodString(string(s.begin(), s.begin() + mid), c + 1);
	cntl += s.size() / 2 - count(s.begin() + mid, s.end(), c);
	int cntr = costForGoodString(string(s.begin() + mid, s.end()), c + 1);
	cntr += s.size() / 2 - count(s.begin(), s.begin() + mid, c);
	return min(cntl, cntr);
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
        string s;
        cin>>s;
        cout<<costForGoodString(s,'a')<<endl;
    }
    return 0;
}