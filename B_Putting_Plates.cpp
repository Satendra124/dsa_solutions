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
        int h,w;
        cin>>h>>w;
        int last = 0;
        for (int i = 0; i < w; i++)
        {
            if(last){
                cout<<0;
                last = 0;
            }else{
                cout<<1;
                last = 1;
            }
        }
        cout<<endl;
        for (int i = 1; i < h-1; i++)
        {
            if(i%2){
                cout<<string(w,'0')<<endl;;
            }else{
                cout<<1<<string(w-2,'0')<<1<<endl;
            }
        }
        last = 0;
        if(h%2){
            if(h>1){
                for (int i = 0; i < w; i++)
                {
                    if(last){
                        cout<<0;
                        last = 0;
                    }else{
                        cout<<1;
                        last = 1;
                    }
                }
                cout<<endl;
            }
            
        }else{
            if(w>=2) cout<<"00";
            else cout<<"0";
            last = 0;
            for (int i = 2; i < w-2; i++)
            {
                if(last){
                    cout<<0;
                    last = 0;
                }else{
                    cout<<1;
                    last = 1;
                }
            }
            if(w>3)cout<<"00";
            else if(w==3) cout<<"0";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}