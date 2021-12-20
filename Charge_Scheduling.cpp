#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef unsigned long long int ll;

class Compare
{
public:
    bool operator() (vector<ll>& a, vector<ll> &b)
    {
        if(a[1]<b[1]) return true;
        else if(a[1]>b[1]) return false;
        return a[0] < b[0];
    }
};
bool cmp(vector<ll>&a,vector<ll>&b){
    if(a[0]<b[0]) return true;
    else if(a[0]>b[0]) return false;
    return a[1] < b[1];
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
        vector<vector<ll>> peps(n,vector<ll>(3)); //TIME: satisfaction time
        for (int i = 0; i < n; i++)
        {
            int a;
            cin>>peps[i][1];
            peps[i][2] = i+1;
        }
        for (int i = 0; i < n; i++)
        {
            cin>>peps[i][0];
        }
        sort(peps.begin(),peps.end(),cmp);
        ll clock = 0;
        vector<vector<ll>> ans;
        priority_queue<vector<ll>,vector<vector<ll>>,Compare> s;
        for (int i = 0; i < n; i++)
        {
            if(s.empty()) {
                if(clock+peps[i][1] <= peps[i][0] ){
                    s.push(peps[i]);
                    clock += peps[i][1];
                }
            }
            else{
                vector<ll> cur = s.top();
                if(clock+peps[i][1] <= peps[i][0] ){
                    s.push(peps[i]);
                    clock += peps[i][1];
                }else{
                    //try remove cur
                    if(clock - cur[1] + peps[i][1] <= peps[i][0] && cur[1]>peps[i][1] ){
                        //remove
                        s.pop();
                        s.push(peps[i]);
                        clock -= cur[1];
                        clock += peps[i][1];
                    }else{
                        //skip
                    }
                }
            }
        }
        vector<vector<ll>> pepsfin;
        while(!s.empty()){
            pepsfin.push_back(s.top());
            s.pop();
        }
        sort(pepsfin.begin(),pepsfin.end(),cmp);
        clock = 0;
         for (int i = 0; i < pepsfin.size(); i++)
        {
            if(clock + pepsfin[i][1] <= pepsfin[i][0] ){
                ans.push_back({pepsfin[i][2],clock,clock + pepsfin[i][1]});
                clock += pepsfin[i][1];
            }
        }
        //if(ans.size()!=pepsfin.size()) cout<<"ERROR"<<endl;
        cout<<ans.size()<<endl;
        for(vector<ll>& v:ans){
            cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
        }
    }
    return 0;
}