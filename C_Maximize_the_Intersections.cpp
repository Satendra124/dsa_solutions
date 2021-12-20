#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

void addEdges(map<int,int> &pairs,int distance,int n,unordered_set<int>& fixed){
    
}

int countIntersection(map<int,int> &pairs,int n){

}

int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n,k;
        map<int,int> pairs;
        unordered_set<int> fixed;
        for (int i = 0; i < k; i++)
        {
            int temp_1,temp_2;
            cin>>temp_1>>temp_2;
            pairs[temp_1] = temp_2;
            pairs[temp_2] = temp_1;
            fixed.insert(temp_1);
            fixed.insert(temp_2);
        }
        int max_inter = 0;
        for (int i = 1; i < n; i++)
        {
            map<int,int> pairs_temp = pairs;
            addEdges(pairs_temp,i,n,fixed);
            max_inter = max(max_inter,countIntersection(pairs_temp,n));
        }
        cout<<max_inter<<endl;
        
    }
    return 0;
}