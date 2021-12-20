#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> allSeq;
vector<int> top4Chance;
vector<double> tieBreaks;
void allSequence(vector<vector<int>> pointsTable,vector<vector<int>> roundTable,int i,int j){
    //cout<<i<<" "<<j<<endl;
    if(i==roundTable.size()-1&&j==roundTable.size()-1){
        allSeq.push_back(pointsTable);
        return;
    }
    // if(i==roundTable.size()||j==roundTable.size()){
    //     return;
    // }
    if(i==j){
        allSequence(pointsTable,roundTable,i+1,j);
        return;
    }
    if(i==roundTable.size()-1) {
        if(roundTable[i][j]==0){
            allSequence(pointsTable,roundTable,0,j+1);
            return;
        }
        pointsTable[i][j] += 2;
        roundTable[i][j]--;
        roundTable[j][i]--;
        allSequence(pointsTable,roundTable,i,j+1);
        pointsTable[i][j] -= 2;
        pointsTable[j][i] += 2;
        allSequence(pointsTable,roundTable,i,j+1);
    }else{

        if(roundTable[i][j]==0){
            allSequence(pointsTable,roundTable,i+1,j);
            return;
        }
        pointsTable[i][j] += 2;
        roundTable[i][j]--;
        roundTable[j][i]--;
        allSequence(pointsTable,roundTable,i,j);
        pointsTable[i][j] -= 2;
        pointsTable[j][i] += 2;
        allSequence(pointsTable,roundTable,i,j);
    }
}

bool comparePoints(pair<int,int> t1,pair<int,int> t2){
   if(t1.first>t2.first) return true;
   else if(t1.first<t2.first) return false;
   else{
       if(tieBreaks[t1.second]>tieBreaks[t2.second]) return true;
       else return false;
   } 
}

void addChances(vector<vector<int>> roundTable){
    int n = roundTable.size();
    vector<pair<int,int>> points(n);
    for (int i = 0; i < n; i++)
    {
        points[i].second = i;
        for (int j = 0; j < n; j++)
        {
            if(roundTable[i][j]!=-1) points[i].first += roundTable[i][j];
        }
    }
    sort(points.begin(),points.end(),comparePoints);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<points[i].first<<" "<<points[i].second<<endl;
    // }
    // cout<<endl<<endl;
    for (int i = 0; i < 4; i++)
    {
        //cout<<i+1<<"."<<points[i].second<<endl;
        top4Chance[points[i].second]++;
    }
    //cout<<"OVER"<<endl;
}

int main()
{
    int n;
    cin>>n;
    clock_t tStart = clock();
    cout<<"ENTER CURRENT MATCHES"<<endl;
    vector<vector<int>> roundTable(n,vector<int>(n,-1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>roundTable[i][j];
        }
    }
    cout<<"ENTER CURRENT POINTS"<<endl;
    vector<vector<int>> pointsTable(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>pointsTable[i][j];
        }
    }
    top4Chance = vector<int>(n,0);
    tieBreaks = vector<double>(n,0.0);
    cout<<"TIE BREAKS"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>tieBreaks[i];
    }
    cout<<"Generating all Possible Results...."<<endl;
    allSequence(pointsTable,roundTable,0,0);
    cout<<"TOTAL POSSIBLE COMBINATIONS: "<<allSeq.size()<<endl;
    for (int i = 0; i < allSeq.size(); i++)
    {
        addChances(allSeq[i]);
    }
    
    int total = allSeq.size();

    for (int i = 0; i < n; i++)
    {
        double ans = double(top4Chance[i])/double(total);
        cout<<ans*100<<"% ";
    }
    cout<<endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}