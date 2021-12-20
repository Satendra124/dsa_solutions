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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int anish_giri = 0;
        int zeroda = 0;
        int last = -1;
        char ans[n][n];
        int loseto[n];
        int winto[n];
        int first = -1;
        for (int i=0;i<n;i++){
            char c = s[i];
            if(c=='1') anish_giri++;
            else {
                zeroda++;
                if(last!=-1) loseto[i] = last;
                else{
                    first = i;
                }
                winto[last] = i;
                last = i;
            }
        }
        if(last!=-1 && first!=-1){
            loseto[first] = last;
            winto[last] = first;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) ans[i][j] = 'X';
                else ans[i][j] = '=';
            }
        }
        for (int i = 0; i < n; i++)
        {
            //cout<<winto[i]<<" "<<loseto[i]<<endl;
            if(s[i]=='2'){
                ans[i][loseto[i]] = '-';
                ans[i][winto[i]]=  '+';
            }
        }
        if(zeroda==1 || zeroda==2){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++) cout<<ans[i][j];
                cout<<endl;
            }
        }
        
    }
    return 0;
}