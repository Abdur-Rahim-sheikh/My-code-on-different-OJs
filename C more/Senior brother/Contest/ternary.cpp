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

    ll i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    char a,b;


    cin>>test;
    while(test--){
        scanf("%lld %c %lld %c %lld",&j,&a,&k,&b,&m);
        ll l1,l2,r1,r2,ans;
        i=0;

        if(a=='/' || a=='*' || a=='%'){


            if(a=='*')ans=j*k;
            else if(a=='/')ans=j/k;
            else ans=j%k;

            if(b=='+')ans=ans+m;
            else if(b=='-')ans-=m;
            else if(b=='*')ans*=m;
            else if(b=='/')ans/=m;
            else ans%=m;



        }
        else {
            if(b=='+')ans=k+m;
            else if(b=='-')ans=k-m;
            else if(b=='*')ans=k*m;
            else if(b=='/')ans=k/m;
            else ans=k%m;


            if(a=='+')ans=j+ans;
            else if(a=='-')ans=j-ans;

        }
        printf("%lld\n",ans);
    }
    //free();   //if pointer array
    return 0;
}
