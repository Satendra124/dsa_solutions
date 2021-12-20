#include <bits/stdc++.h>
using namespace std;

int binaryS(vector<int> a,int target){
    int r = a.size()-1;
    int l =0;
    int ans=  -1;
    while (l<=r)
    {
        int mid = l + (r-l)/2;
        if(a[mid]>=target){
            ans = mid;
            r = mid-1;
        }else{
            l = mid + 1;
        }
    }
    return ans;
    
}
int main()
{
    int n;
    cin>>n;
    vector< vector<int> > army(n);
    for (int i = 0; i < n; i++)
    {
        int si;
        cin>>si;
        for (int j = 0; j < si; j++)
        {
            int temp;
            cin>>temp;
            army[i].push_back(temp);
        }
        
    }
    
    int q;
    cin>>q;
    while (q--)
    {
        int v;
        cin>>v;
        if(v==0){
            int k;
            cin>>k;
            k--;
            army[k].pop_back();
        }else if(v==1){
            int k,h;
            cin>>k>>h;
            //insert k of height h
            k--;
            if(k==0){
                army[k].push_back(h);
            }else{
                army[k].push_back(h);
                sort(army[k].begin(),army[k].end());
            }
            
            
        }else{
            int cur = *min_element(army[0].begin(),army[0].end());
            bool canUse = true;
            for (int i = 1; i < n; i++)
            {
                int next = binaryS(army[i],cur);
                if(next==-1) {
                    canUse = false;
                    break;
                }
                cur = army[i][next];
            }
            if(canUse){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        
        }
        // cout<<"army currently: "<<endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < army[i].size(); j++)
        //     {   
        //         cout<<army[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        

    }
    
}