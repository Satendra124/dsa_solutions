//some

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef unsigned long long int ll;
int main()
{
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        ll no;
        int s;
        cin>>no>>s;
        string num = to_string(no);
        
        
        int sum = 0;
        int n = num.length();

        for (int i = 0; i < n; i++)
        {
            sum += num[i]-'0';   
        }
        if(sum<=s){
            cout<<0<<endl;
            continue;
        }
        int totalS = sum;
        sum = 0;
        int i = 0;
        int p = -1;
        string num2;
        while(i<n&&sum+num[i]-'0'<s){
            sum += num[i]-'0';
            i++;
            p++;
        }
        if(p==-1){
            num2.push_back('1');
            num2.append(string(n,'0'));
           // cout<<num2<<endl;
            ll other = stoull(num2);
            cout<<other - no<<endl;
            continue;
        }
        for (int j = 0; j < p; j++)
        {
            num2.push_back(num[j]);
        }
        num2.push_back(num[p]+1);
        for (int k = p+1; k < n; k++)
        {
            num2.push_back('0');
        }
        ll other = stoull(num2);
        cout<<other - no<<endl;
       // cout<<num2<<" "<<i<<" "<<p<<endl;        
    }   
    return 0;
}