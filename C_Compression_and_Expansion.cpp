#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

string process(string lev,int lastNo){
    int pos = -1;
    for (int i = lev.length()-1; i >=0; i--)
    {
        if(lev[i]=='.'){
            pos = i;
            break;
        }
    }

    string fin = lev.substr(0,pos+1) + to_string(lastNo+1);
    return fin;
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
        vector<string> ans;
        stack<pair<int,string>> s;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        s.push({arr[0],"1"});
        ans.push_back("1");
        for (int i = 1; i < n; i++)
        {
            int lastNo =  s.top().first;
            string lev = s.top().second;
            if(arr[i]==lastNo+1){
                //make cur from 1.2.3 to 1.2.4
                //or 1.2.23 to 1.2.24
                string cur = process(lev,lastNo);
                ans.push_back(cur);
                s.top().first++;
                s.top().second = cur;
            }else if(arr[i]==1){
                string cur = lev;
                cur.append(".1");
                ans.push_back(cur);
                s.push({1,cur});
            }else{
                s.pop();
                i--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}