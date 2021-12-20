#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

bool sortfn(vector<double>&a,vector<double>&b) {
    //sort according to price
    return a[1]<b[1];
}
bool rangeCheck(double num,double l,double r){
    if(num>=l && num<=r) return true;
    else return false;
}
int solves(vector<vector<double>>& foods){
    int n = foods.size();
    double last = 0;
    int ans  = 0;
    for (int i = 0; i < n-1; i++)
    {
        double cur = foods[i][0];
        double next = foods[i+1][0];
        if(last > cur){
            cur = max(last + 1e-7,foods[i][2]);
            if(rangeCheck(cur,foods[i][2],foods[i][3])) ans++;
            else return -1;
        }else if(last==cur){
            //donot reduce current
            cur +=1e-7;
            if(rangeCheck(cur,foods[i][2],foods[i][3])){
                ans++;
                
            }else return -1;
        }

        if(cur>next){
            if(cur!=foods[i][0]) return -1;
            else{
                double temp = cur;
                cur = max(next - 1e-7,foods[i][2]);
                if(rangeCheck(cur,foods[i][2],foods[i][3]) && last<cur) ans++;
                else cur = temp;
            }
        }else if(cur==next){
            cur -=1e-7;
            if(rangeCheck(cur,foods[i][2],foods[i][3])){
                ans++;
                
            }
        }
        

        last = cur;
    }
    return ans;

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
        vector<vector<double>> foods(n,vector<double>(4));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin>>foods[i][j];   
            }
        }
        sort(foods.begin(),foods.end(),sortfn);
        int ans = solves(foods);
        cout<<ans<<endl;
    }
    return 0;
}




// if(last>cur){
//             //change
//             if(last>=foods[i][2] && last<=foods[i][3])
//                 ans++;
//             else return -1;
//             //last = last
//         }else if(last==foods[i][0] && !flag){
//             //just inc 
//             if(foods[i][3]>foods[i][0]) {
//                 ans++;
//                 flag = true;
//             }
//             else return -1;
//         }
//         else{
//             if(i<n-1 && foods[i][0]>foods[i+1][0]){
//                 //reduce as low as possible
//                 if(foods[i][2]<foods[i+1][0]){
//                     last = foods[i][2];
//                     flag = false;
//                     ans++;
//                 }
                
//             }else if(i<n-1 && foods[i][0]==foods[i+1][0]){
//                 //change small
//                 if(foods[i][0]>foods[i][2]) ans++;
//                 else return -1;
//                 flag = true;
//             }else flag = false;
//         }