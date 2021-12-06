#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>m>>k;
        printf("Case %d: ",++t);
        if((k%__gcd(n,m))==0)printf("Yes\n");
        else printf("No\n");
    }
    //free();   //if pointer array
    return 0;
}
