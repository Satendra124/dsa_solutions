#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

int solve(string s){
    //find even nums
    //find one
    for(char& c:s){
        if((c-'0')%2==0 && (c-'0')!=2){
            cout<<1<<endl<<c-'0'<<endl;
            return 1;
        }else if(c-'0'==1){
            cout<<1<<endl<<1<<endl;
            return 1;
        }else if(c=='9'){
            cout<<1<<endl<<9<<endl;
            return 1;
        }
    }
    //find five in anywhere except 1st pos
    //find 2 in anywhere except 1st pos
    for(int i=1;i<s.size();i++){
        if(s[i]=='2'){
            cout<<2<<endl<<s[i-1]<<s[i]<<endl;
            return 1;
        }else if(s[i]=='5'){
            cout<<2<<endl<<s[i-1]<<s[i]<<endl;
            return 1;
        }
    }
    //find repeating
    int past[10];
    memset(past,0,sizeof(past));
    for(char& c:s){
        if(past[c-'0']){
            cout<<2<<endl<<c<<c<<endl;
            return 1;
        }else past[c-'0']++;
    }
    //only left are 237 , 273,327,372,723,732
    if(s=="237"||s=="27"){
        cout<<2<<endl<<27<<endl;
        return 1;
    }else if(s=="273"){
        cout<<2<<endl<<27<<endl;
        return 1;
    }else if(s=="57"|| s=="573"||s=="537" ){
        cout<<2<<endl<<57<<endl;
        return 1;
    }
    else{
        cout<<"1"<<endl<<"-1"<<endl;
        return 0;
    }

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
        string s;
        cin>>s;
        // for(int i=1;i<1000000000;i++){
        //     string s = to_string(i);
        //     int ans = solve(s);
        //     if(ans==0){
        //         cout<<"............."<<i<<endl;
        //     }
        // }
        solve(s);
        

    }
    return 0;
}