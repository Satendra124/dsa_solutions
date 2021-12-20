#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int scores[n][5];
        for (int i = 0; i < n; i++)
        {
            int s[5];
            for (int j = 0; j < 5; j++)
            {
                cin>>scores[i][j];
            }
        }
        map<int,vector<int>> scores_fin;
        vector<int> parts;
        for (int i = 0; i < 5; i++)
        {
            //scores[0-n][i]
            vector<pair<int,int>> v;
            for (int j = 0; j < n; j++)
            {
                v.push_back({scores[j][i],j});
            }
            sort(v.begin(),v.end());
            for (int k = 0; k < n; k++)
            {
                scores_fin[v[k].second].push_back(k);
                parts.push_back(v[k].second);
            }
        }
        map<int,int> scores_cal;
        for (int i = 0; i < n; i++)
        {
            vector<int> this_score = scores_fin[parts[i]];
            sort(this_score.begin(),this_score.end());
            scores_cal[parts[i]] = this_score[0] +this_score[1]+this_score[2];
        }
        
        
        bool possible = true;
        int ans = -1;
        int minScore = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if(minScore>scores_cal[parts[i]]){
                minScore = scores_cal[parts[i]];
                ans = parts[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(minScore==scores_cal[parts[i]] && ans != parts[i]) possible = false;
        }
        if(possible) cout<<ans+1<<endl;
        else cout<<-1<<endl;
        
        
    }
    return 0;
}