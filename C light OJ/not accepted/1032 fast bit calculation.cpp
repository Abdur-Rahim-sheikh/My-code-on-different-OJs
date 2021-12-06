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

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    int total=0;
    for(i=1;i<129;i++){
        j=i+1;
        cnt=0;
        while(j%2==0)j=j>>1,cnt++;
        k=i;
        int sum=0;
        while(k){
            while(!(k&1))k=k>>1;
            while(k&1)k=k>>1,sum++;
            sum--;
        }
        total+=sum;
        cout<<i<<' '<<sum<<' '<<total<<endl;
        if(j==1)total=0,cout<<endl<<cnt+1<<" bit section"<<endl<<endl;

    }
    //free();   //if pointer array
    return 0;
}
