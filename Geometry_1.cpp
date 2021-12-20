#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int ll;
long double inf = 1e7;
long double pi = M_PI;

long double polygonArea(long double X[], long double Y[], int n)
{
    long double area = 0.0;
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i; 
    }
    return abs(area / 2.0);
}

long double sigmaL(long double x[],long double y[],int n){
    long double ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        ans += sqrt( (x[i]-x[i+1])*(x[i]-x[i+1]) + (y[i]-y[i+1])*(y[i]-y[i+1]) );
    }
    ans += sqrt( (x[0]-x[n-1])*(x[0]-x[n-1]) + (y[0]-y[n-1])*(y[0]-y[n-1]));
    return ans;
}
long double sigmaTanThetaBy2(long double x[],long double y[],int n){
    long double m[n];
    for (int i = 0; i < n-1; i++)
    {
        if(x[i]==x[i+1]){
            m[i] = inf;
        }else m[i] = (y[i]-y[i+1])/(x[i]-x[i+1]);
    }
    if(x[n-1]==x[0]){
        m[n-1] = inf;
    }else m[n-1] = (y[n-1]-y[0])/(x[n-1]-x[0]);
    long double tan_theta[n];

    for (int i = 0; i < n-1; i++)
    {
        long double tan_thetat = - (m[i] - m[i+1])/(1+m[i]*m[i+1]);
        if(m[i]*m[i+1]==-1 || (m[i]==0 && m[i+1]==inf) || (m[i]==inf && m[i+1]==0) ) tan_thetat = inf;
        tan_theta[i] = tan_thetat;
    }
    if(m[n-1]*m[0]==-1 || (m[n-1]==0 && m[0]==inf) || (m[n-1]==inf && m[0]==0)) tan_theta[n-1] = inf;
    else tan_theta[n-1] = -(m[n-1] - m[0])/(1+m[n-1]*m[0]);

    long double sublen[n];//radian
    for (int i = 0; i < n; i++)
    {
        if(tan_theta[i]==inf) sublen[i] = 1;
        else if(tan_theta[i]>0){
            sublen[i] = (-1 + sqrt(1+tan_theta[i]*tan_theta[i]))/tan_theta[i];
        }else{
            sublen[i] = (-1 - sqrt(1+tan_theta[i]*tan_theta[i]))/tan_theta[i];
        }
        
    }
    long double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += sublen[i];
    }
    return ans;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,q;
        cin>>n>>q;
        long double x[n];
        long double y[n];
        long double hs[q];
        for (int i = 0; i < n; i++)
        {
            cin>>x[i]>>y[i];
        }
        for (int i = 0; i < q; i++)
        {
            int v,t;
            cin>>v>>t;
            hs[i] = v*t;
        }
        //part 1 : CURRENT AREA
        long double initial_area = polygonArea(x,y,n);
        //part 2: sigma l
        long double sigma_l = sigmaL(x,y,n);
        //part3: sigma_cot_theta_by_2
        long double sigma_tan_theta_by_2 =sigmaTanThetaBy2(x,y,n);
        long double ans = 0;
        for (int i = 0; i < q; i++)
        {
            long double h = hs[i];
            ans =initial_area + h*sigma_l + h*h*sigma_tan_theta_by_2;
            cout<<ans<<endl;
        }
        
    }
    return 0;
}