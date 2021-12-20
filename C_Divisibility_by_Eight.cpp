#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

string no;

int main()
{
    fast;
    cin>>no;
    int n = no.length();
    bool ans = false;
    string ansS = "";
    for (int i = 0; i < n&&!ans; i++)
    {
        int num3 =(no[i]-'0');
            if(num3%8==0) {
                ans=true;
                ansS =  to_string(num3);
            }
        for (int j = i+1; j < n&&!ans; j++)
        {
            int num2 =10*(no[i]-'0') + (no[j]-'0');
            if(num2%8==0) {
                ans=true;
                ansS =  to_string(num2);
            }
            for (int k = j+1; k < n&&!ans; k++)
            {
                int num = 100*(no[i]-'0') + 10*(no[j]-'0') + (no[k]-'0');
                if(num%8==0) {
                    ans=true;
                    ansS =  to_string(num);
                }
            }
            
            
        }
        
    }
    
    if(ans){
    cout<<"YES"<<endl;
    cout<<ansS<<endl;}
    else cout<<"NO"<<endl;
    
}