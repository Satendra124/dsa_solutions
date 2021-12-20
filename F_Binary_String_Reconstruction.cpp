#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int n0,n1,n2;
        cin>>n0>>n1>>n2;
        string ans = "";
        if(n1>0){
            if(n0>0){
                // all zero then all 1 then 0 1 01 till n1 ends
                ans.append(string(n0+1,'0'));
                if(n2>0){
                    ans.append(string(n2+1,'1'));
                    int no = 0;
                    n1--;
                    while(n1--){
                        ans.push_back(no+'0');
                        no = !no;
                    }
                }else{
                    //all zero then 1 0 1 0
                    int no = 1;
                    while(n1--){
                        ans.push_back(no+'0');
                        no = !no;
                    }
                }
            }else{
                //no zero  -  all once then  0 1 0 1
                ans.append(string(n2+1,'1'));
                int no = 0;
                while(n1--){
                    ans.push_back(no+'0');
                    no = !no;
                }
            }
        }else{
            // no zero and once together means just all zero then all one

            if(n0) ans.append(string(n0+1,'0'));
            if(n2) ans.append(string(n2+1,'1'));
        }
        cout<<ans<<endl;
    }
    return 0;
}