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

    int i,j,k,m,n,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);

    cin>>test;
    bool l,r;

    while(test--){
        string a,b,c,d;
        l = r = false;
        cin>>n>>a>>b;
        for(i=0;i<n;i++){
            if(a[i]!=b[i]){
                c+=a[i];
                d+=b[i];
            }
        }

        n= c.size();
        ///cout<<c<<' '<<d<<endl;
        for(i=0;i<n;i++)if(c[i]!=d[(i+1)%n])break;
        if(i==n)l=true;

        for(i=0;i<n;i++)if(c[(i+1)%n]!=d[i])break;
        if(i==n)r=true;

        if(n==0 || l || r)printf("YES\n");
        else printf("NO\n");
    }
    //free();   //if pointer array
    return 0;
}
