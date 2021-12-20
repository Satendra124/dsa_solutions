#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,s;
    cin>>m>>s;
    string maxNo = string(m,'0');
    string minNo = string(m,'0');
    //finding max
    int s2 = s;
    int i = 0;
    if(s==0&&m==1){
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    if(s<=9*m&&s>0){
        while (s>0)
        {
            int k = min(s,9);
            s-=k;
            if(i>m-1) {
                maxNo = "-1";
                break;
            }
            maxNo[i++]=k+48;
        }
    }else{
        maxNo = "-1";
    }
    i = m-1;
    if(s2<=9*m&&s2-1>0){
        while (s2-1>0&&i>0)
        {
            int k = min(s2-1,9);
            s2-=k;
            minNo[i--]=k+48;
           // cout<<s2<<endl;
        }
        minNo[0] = 48+s2;
    }else{
        if(s2>0&&s<=9*m){
            minNo[0] = '1';
        }
        else minNo = "-1";
    }
    cout<<minNo<<" "<<maxNo<<endl;
    return 0;
}