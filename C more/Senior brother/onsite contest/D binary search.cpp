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

    int i,j,k,m,n,val,t=0,test,arr[200000]={0},sign[200000]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)    scanf("%d",&arr[i]);

    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&val);
        for(j=0,k=n-1;j<=k;  )
        {
            if(val==arr[(j+k)/2]) {
                if(sign[(j+k)/2]==1)
                break;

                t++;
                sign[(j+k)/2]=1;
                break;
            }

            else if(val>arr[(j+k)/2])j=(j+k)/2+1;
            else  k=(j+k)/2-1;
        }
    }
    printf("%d\n",t);
    //free();   //if pointer array
    return 0;
}
