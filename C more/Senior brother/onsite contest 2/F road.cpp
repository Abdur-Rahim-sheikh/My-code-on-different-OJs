
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test,arr[100000],prev,save;

    cin>>test;
    while(test--){
        scanf("%d %d",&n,&k);
        for(i=0,j=0,save=0;i<n;i++){
            scanf("%d",&val);
            if(val==0)
                arr[j++]=i+1;
        }
        if(j<=k)printf("%d\n",n);
        else{
            for(i=0,prev=1;i+k<j;i++){
                if(arr[k+i]-prev>save){
                    save=arr[k+i]-prev;
                }
                prev=arr[i]+1;      //pushing +1 cause previous is less 1 then boundary where arr[k+1] is 1 more then boundary so i in total i had to increase prev++,or arr[k+1]--,so i did prev++
            }
            if(n-arr[i-1]>save) save=n-arr[i-1];
            printf("%d\n\n",save);
        }
    }
    //free();   //if pointer array
    return 0;
}
