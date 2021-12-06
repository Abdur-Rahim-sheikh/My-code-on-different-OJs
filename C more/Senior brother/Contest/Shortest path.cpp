#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;

int main()
{

    int i,j,cnt,test;
    //freopen("000input.txt","r",stdin);
    double a,b,c,d,x,p,t,k,l,r,ans;
    cin>>test;
    while(test--){
        scanf("%lf %lf %lf %lf",&a,&b,&c,&x);
        d=sqrt(a*a+b*b);
        t = (d/x)*100;
        k = (a*t)/d;
        l = a-k;
        r = b+c-sqrt(t*t-k*k);
        ans = t+c+sqrt(l*l+r*r);
        ans+=(c+sqrt((a*a)+((b+c)*(b+c))));
        cout<<ans<<endl;
    }
    //free();   //if pointer array
    return 0;
}
