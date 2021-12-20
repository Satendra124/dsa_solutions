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
        string s;
        cin>>s;
        regex rc("R[\d]+C[\d]+");
        if(regex_match(s,rc)){
            //RC type
            string n1S = "";
            string n2S = "";
            bool secNo = false;
            for (int i = 0; i < s.length(); i++)
            {
                if(s[i]!='R'||s[i]!='C'){
                    if(secNo) n2S.push_back(s[i]);
                    else n1S.push_back(s[i]);
                }else if(s[i]=='C') secNo = true;
            }
            int row = stoi(n1S);
            int col = stoi(n2S);

            //convert col to alpha numberings
            int numOfDigits = 1;
            int p = 1;
            int c = col;
            while(c){
                c -= pow(26,p++);
                numOfDigits++;
            }
            
            
        }else{

        }
        
    }
    return 0;
}