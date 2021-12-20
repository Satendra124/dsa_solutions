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
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>b[i];
        }
        int rounds = n;
        int ascore = 0;
        int bscore = 0;
        for (int i = 0; i < n; i++)
        {
            ascore += a[i];
            bscore += b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        int delEle = n/4;
        for (int i = 0; i < delEle; i++)
        {
            ascore -= a[i];
            bscore -= b[i];
        }
        int da = delEle;
        int db = delEle-1;
        while(ascore<bscore){
            rounds++;
            if(rounds%4==0){
                if(da<n && int(rounds/4)>0){
                    ascore += 100 - a[da];
                    da++;
                }else{
                    ascore += 100;
                }
            }else{
                if(db>=0 && int(rounds/4)>0){
                    ascore += 100;
                    bscore += b[db];
                    db--;
                }else{
                    ascore +=100;
                }
            }
        }
        cout<<rounds-n<<endl;
    }
    return 0;
}