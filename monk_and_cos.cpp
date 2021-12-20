#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector< pair<int,int> > nos(n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        nos[i].first = i;
        nos[i].second = temp;
    }
    int noOfloops = x;
    while (noOfloops--)
    {
        int k = x - noOfloops-1;
        int maxI = 0;
        int maxNo = INT_MIN;
        for (int i = k; i < k*x+x; i++)
        {
            int p = i - (n-1)*(i/(n-1));
            cout<<"p: "<<p<<endl;
            if(maxNo<nos[p].second) {
                maxNo = nos[p].second;
                maxI = nos[p].first;
            }
            if(nos[p].second>0)
            nos[p].second--;
        }
        nos.erase(nos.begin()+maxI);
        for (int i = 0; i < nos.size(); i++)
        {
            cout<<nos[i].second<<"-"<<nos[i].first<<" ";
        }
        cout<<endl;
        
        cout<<maxI+1<<" "<<maxNo;
    }
    

    return 0;
}