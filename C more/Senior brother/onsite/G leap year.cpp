#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,n,val,t=0,test,d,m,y,upto,seleb=0;

    cin>>test;
    while(test--){
            seleb=0;
        scanf("%d %d %d %d",&d,&m,&y,&upto);
        if(d==29 && m==2){
            for(i=y+4;i<=upto;i=i+4){
                if (i % 400 == 0)seleb++;
               // else if(year % 100 == 0) return false;
                else if(i % 4 == 0 && i%100!=0)seleb++;
            }
            printf("Case %d: %d\n",++t,seleb);
        }
        else{
            printf("Case %d: %d\n",++t,upto-y);
        }
    }
    //free();   //if pointer array
    return 0;
}
