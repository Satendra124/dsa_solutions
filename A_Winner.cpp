//BLIND IMPLEMENTATION

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int r;
    cin>>r;
    map<string,int> pointsTable;
    vector<pair<string,int>> data;
    int maxScore = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        string name;
        int score;
        cin>>name>>score;
        if(pointsTable[name]) {
            pointsTable[name] += score;
        } else{
            pointsTable[name] = score;
        }
        data.push_back({name,score});
    }
    map<string, int>::iterator itm;
    for (itm = pointsTable.begin(); itm != pointsTable.end(); itm++)
    {
        maxScore = max(maxScore,itm->second);
    }
    //we know [maxScore] is winner score so need to find who got it first
    //fetch candidates
    vector<string> candidates;
    map<string, int>::iterator it;
    for (it = pointsTable.begin(); it != pointsTable.end(); it++)
    {
        if(it->second == maxScore){
            candidates.push_back(it->first);
           //cout<<"candidate: "<<it->first<<endl;
        }
    }

    //check which candidates reached to maxScore first
    //cout<<"m: "<<maxScore<<endl;
    map<string,int> pointsTableN;
    string ans = "didnotfind";
    for(int i = 0;i<r;i++){
        if(pointsTableN[data[i].first]) {
            pointsTableN[data[i].first] += data[i].second;
            if(pointsTableN[data[i].first]>=maxScore && find(candidates.begin(),candidates.end(),data[i].first)!=candidates.end()){
                ans = data[i].first;
                break;
            }
        } else{
            pointsTableN[data[i].first] = data[i].second;
            if(pointsTableN[data[i].first]>=maxScore && find(candidates.begin(),candidates.end(),data[i].first)!=candidates.end()){
                ans = data[i].first;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}