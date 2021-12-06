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

    cin>>test;
    while(test--){
        scanf("%lld %lld",&m,&n);
        ll s1=0,s2=0;
        for(i=0;i<m;i++)scanf("%lld",&val),s1+=val;
        for(i=0;i<n;i++)scanf("%lld",&val),s2+=val;
        if(s1>s2)printf("Calem\n");
        else if(s1<s2)printf("Serena\n");
        else printf("Draw\n");

    }
    //free();   //if pointer array
    return 0;
}
