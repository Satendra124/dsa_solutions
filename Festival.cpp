// #include <bits/stdc++.h>
// using namespace std;
// int mod = 1e9+7;
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// typedef long long int ll;

// void update(int start,int end,int index,int value,ll segtree[],int s,int e,int k,int ks[]){
//     if(start>=s && end<=e){ //in range
//         //update this node and all below it
//         if(ks[index]<k){
//             segtree[index] = (segtree[index]+value)%mod;
//             ks[index]++;
//         }
//         //cout<<start<<" "<<end<<" "<<segtree[index]<<endl;
//     }
//     if(start!=end && !(start>e || end<s)){
//         int mid = (start+end)/2;
//         update(start,mid,2*index+1,value,segtree,s,e,k,ks);
//         update(mid+1,end,2*index+2,value,segtree,s,e,k,ks);
//     }
// }

// ll give_me_intern_google(){
//     int d,n,k;
//     cin>>d>>n>>k;
//     int size = 2*d+2;
//     ll segtree[size];
//     int ks[size];
//     memset(segtree,0,sizeof(segtree));
//     memset(ks,0,sizeof(ks));
//     vector<vector<int>> ques;
//     for (int i = 0; i < n; i++)
//     {
//         int h,s,e;
//         cin>>h>>s>>e;
//         ques.push_back({h,s,e});
//     }
//     sort(ques.begin(),ques.end(),greater<vector<int>>());
//     for (int i = 0; i < ques.size(); i++)
//     {
//         int h=ques[i][0],s=ques[i][1],e=ques[i][2];
//         update(1,d,0,h,segtree,s,e,k,ks);
//     }
//     ll ans = 0;
//     for (int i = 0; i < size; i++)
//     {
//         ans = max(ans,segtree[i]);
//     }
//     return ans;
    
// }


// int main()
// {
//     fast;
//     int t;
//     cin>>t;
//     int d = t;
//     while (t--)
//     {
//         cout<<"Case #"<<d - t<<": "<<give_me_intern_google()<<endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

void update(int start,int end,int index,int value,int segtree[],int s,int e,int k,int ks[]){
    if(start>=s && end<=e){ //in range
        //update this node and all below it
        if(ks[index]<k){
            ll ans = segtree[index];
            ans +=value;
            segtree[index] = (ans)%mod;
            ks[index]++;
        }
        //cout<<start<<" "<<end<<" "<<segtree[index]<<endl;
    }
    if(start!=end && !(start>e || end<s)){
        int mid = (start+end)/2;
        update(start,mid,2*index+1,value,segtree,s,e,k,ks);
        update(mid+1,end,2*index+2,value,segtree,s,e,k,ks);
    }
}

ll give_me_intern_google(){
    int d,n,k;
    //cin>>d>>n>>k;
    d=3e5,n=3e5,k=3e5;
    int segtree[1000000];
    int ks[1000000];
    memset(segtree,0,sizeof(segtree));
    memset(ks,0,sizeof(ks));
    vector<vector<int>> ques;
    for (int i = 0; i < n; i++)
    {
        int h,s,e;
        h = 3e5,s=1,e=3e5;
        //cin>>h>>s>>e;
        ques.push_back({h,s,e});
    }
    sort(ques.begin(),ques.end(),greater<vector<int>>());
    for (int i = 0; i < ques.size(); i++)
    {
        int h=ques[i][0],s=ques[i][1],e=ques[i][2];
        update(0,d+1,0,h,segtree,s,e,k,ks);
    }
    int ans = 0;
    for (int i = 0; i < 1000000; i++)
    {
        ans = max(ans,segtree[i]);
    }
    return ans;
    
}


int main()
{
    fast;
    int t;
    cin>>t;
    int d = t;
    while (t--)
    {
        cout<<"Case #"<<d - t<<": "<<give_me_intern_google()<<endl;
    }
    return 0;
}