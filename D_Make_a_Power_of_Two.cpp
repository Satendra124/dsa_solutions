#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int count_diff(string s, int ss, string n, int ns)
{
    int i = 0,j=0;
    int del = 0;
    int same = 0;
    while(i<ss && j<ns){
        if(s[i] != n[j]){
            //delete
            j++;
            del++;
        }else {
            same++;
            i++;
            j++;
        }
    }
    del += ss-i + ns - j;
    return del;
}
 
int main()
{
    fast;
    int t;
    cin>>t;

    vector<string> pow_o_2;
    for(int i=0;i<60;i++){
        unsigned long long k = pow(2,i);
        pow_o_2.push_back(to_string(k));
    }
    while (t--)
    {
        string n;
        cin>>n;
        int min_dif_dig = INT_MAX;
        for(int i=0;i<60;i++){
            string cur = pow_o_2[i];
            min_dif_dig = min(min_dif_dig,count_diff(cur,cur.size(),n,n.size()));
        }
        cout<<min_dif_dig<<endl;
    }
    return 0;
}