#include<stdio.h>
int main(){

    int n,val,sum=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&val);
        if(val>0)sum=sum+val;
    }
    printf("%d",sum);
}
