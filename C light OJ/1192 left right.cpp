#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,prev;

    //freopen("000input.txt","r",stdin);

    cin>>test;

    while(test--){
        scanf("%d",&n);
        int sum=0;
        for(i=0;i<2*n;i++){
            scanf("%d",&val);
            if(i&1)sum^=(val-prev-1);
            prev=val;
        }
        if(sum)printf("Case %d: Alice\n",++t);
        else printf("Case %d: Bob\n",++t);
    }



    //free();   //if pointer array
    return 0;
}
