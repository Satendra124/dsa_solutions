#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int search(vector<int> v,int target){
    for (int i = v.size()-1; i >=0; i--)
    {
        if(v[i]==target) return i;
    }
    return -1;
}

int main()
{
    fast;
    int n,q;
    cin>>n>>q;
    vector<int> cards(n);
    for (int i = 0; i < n; i++) cin>>cards[n-i-1];
    map<int,int> history;
    for (int i = 0; i < q; i++)
    {
        int query;
        cin>>query;
        if(history[query]){
            cout<< i- history[query]<<" ";
            cards.erase(cards.begin()+n-1-(i-history[query]-1));
            cards.push_back(query);
            history[query] = i;
        }else{
            int s = search(cards,query);
            cout<<n-s<<" ";
            cards.erase(cards.begin()+ s);
            cards.push_back(query);
            history[query] = i;
        }
    }
    
    
    return 0;
}