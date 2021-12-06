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

int main(){

    int i,j,k,m,n,val,t=0,cnt,test,left_big;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>left_big;
        int no_less_then=1;
        for(i=1;i<n;i++){
            scanf("%d",&left_big);

            ///if left side of i has k bigger and i am(first index)
            ///bigger then m so if(m+k)>=i i am bigger then i'th value
            if(i<no_less_then+left_big)no_less_then++;
        }

        printf("Case %d: %d\n",++t,no_less_then);
    }
    //free();   //if pointer array
    return 0;
}
