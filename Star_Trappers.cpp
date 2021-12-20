#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
typedef long double ld;
ld area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
bool isInside(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3, ll x, ll y)
{  
   ld A = area (x1, y1, x2, y2, x3, y3);
  
   ld A1 = area (x, y, x2, y2, x3, y3);
  
   ld A2 = area (x1, y1, x, y, x3, y3);
  
   ld A3 = area (x1, y1, x2, y2, x, y);
    
   return (A == A1 + A2 + A3);
}

ld perimeter(int ax,int bx,int cx,int ay,int by,int cy){
    ld A = sqrt((ld)(bx-ax) * (bx-ax) + (by-ay) * (by-ay));

    ld B = sqrt((ld)(bx-cx) * (bx-cx) + (by-cy) * (by-cy));

    ld C = sqrt((ld)(ax-cx) * (ax-cx) + (ay-cy) * (ay-cy));
    return A+B+C;
}

int main()
{
    fast;
    int t;
    cin>>t;
    int d = t;
    while (t--)
    {
        int n;
        cin>>n;
        int bx,by;
        int wx[n],wy[n];
        for (int i = 0; i < n; i++)
        {
            cin>>wx[i]>>wy[i];
        }
        cin>>bx>>by;
        ld ans = 1e8;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    if(isInside(wx[i],wx[j],wx[k],wy[i],wy[j],wy[k],bx,by))
                        ans = min(ans,perimeter(wx[i],wx[j],wx[k],wy[i],wy[j],wy[k]));
                }
            }
        }
        cout<<fixed<<setprecision(6);
        if(ans==1e8) cout<<"Case #"<<d - t<<": "<<"IMPOSSIBLE"<<endl;
        else cout<<"Case #"<<d - t<<": "<<ans<<endl;
    }
    return 0;
}