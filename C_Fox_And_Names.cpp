#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;


string ans = "";
bool possible = true;
int state[27];

void addEdges(vector<vector<bool>>& graph,string& s1,string& s2){
    int i = 0;
    while(i<s1.size() && i<s2.size()){
        if(s1[i]!=s2[i]) break;
        i++;
    }
    if(i<s1.size() && i<s2.size() && s1[i]!=s2[i]){
        graph[s1[i]-'a'][s2[i]-'a'] = true;
        //cout<<"SAd"<<endl;
    }
    else if(s1.size()>s2.size()){
        possible = false;
        return;
    }
    else return;
}

void dfs(vector<vector<bool>>& graph,int cur){
    // if(cur=='t'-'a' || cur=='r'-'a'){
    //     //cout<<"sd";
    // }
    if(state[cur]==1) {
        possible = false;
        //cout<<"sda"<<endl;
        return;
    }
    if(state[cur]==2) return;
    state[cur] = 1;
    for (int i = 0; i < 26; i++)
    {
        if(graph[cur][i] && i != cur) dfs(graph,i);
    }
    
    ans.push_back(cur+'a');
    state[cur] = 2;
}

string topo_sort(vector<vector<bool>>& graph){
    memset(state,0,sizeof(state));
    for(int i=0;i<26;i++){
        dfs(graph,i);
    }
    reverse(ans.begin(),ans.end());
    if(possible) return ans;
    else return "Impossible";
}

int main()
{
    fast;
    int n;
    cin>>n;
    string authors[n];
    for (int i = 0; i < n; i++)
    {
        cin>>authors[i];
    }
    vector<vector<bool>> graph(26,vector<bool>(26,false));
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            addEdges(graph,authors[i],authors[j]);
        }
    }
    // for (int i = 0; i < 26; i++)
    // {
    //     cout<<(char(i+'a'))<<"   ";
    //     for (int j = 0; j < 26; j++)
    //     {
    //         cout<<(graph[i][j])<<" ";
    //     }
    //     cout<<endl;
        
    // }
    //Topological sort
    string topo = topo_sort(graph);
    cout<<topo<<endl;
    return 0;
}