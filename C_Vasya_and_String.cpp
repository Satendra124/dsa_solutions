#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int amax = 0;
    int bMax = 0;
    int p = k;
    bool running = false;
    int cura = 0;
    vector<int> same;
    vector<int> dif;
    for (int i = 0; i < n; i++)
    {
        if(running){
            if(s[i]=='a'){
                cura++;
            }else{
                
            }
        }else if(s[i]=='a') running = true;
    }
    return 0;
}