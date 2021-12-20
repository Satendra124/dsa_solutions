#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

char mc = 'a';
bool comp(pair<int,string> a,pair<int,string> b){
    return a.first>b.first;
}
int getcnt(string a){
    int acnt = 0;
    for(char c:a) if(c==mc) acnt++;
    return acnt;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int rec[26];
        memset(rec,0,sizeof(rec));
        int n;
        cin>>n;
        string words[n];
        for (int i = 0; i < n; i++)
        {
            cin>>words[i];
        }
        char maxChar;
        int maxCharNum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                rec[words[i][j]-'a']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if(maxCharNum<rec[i]){
                maxCharNum = rec[i];
                maxChar = i+'a';
            }
        }
        mc = maxChar;
        vector<pair<int,string>> fin;
        for (int i = 0; i < n; i++)
        {
            int cnt = getcnt(words[i]);
            fin.push_back({cnt,words[i]});
        }
        sort(fin.begin(),fin.end(),comp);
        int extra = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if(fin[i].first>(fin[i].second.size()+1)/2){
                //great
                extra += 2*fin[i].first - fin[i].second.size();
            }else{
                extra -= fin[i].second.size() - 2*fin[i].first;
                if(extra<=0) break;
            }
            cnt++;
        }
        cout<<cnt<<endl;
        
        
    }
    return 0;
}