#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the value : ");
    scanf("%d %d",&a,&b);
    int i=0;
    while(a<=b){
        a=a*3;
        b=b*2;
        i++;
    }
    printf("%d %d %d",i,a,b);
    return 0;
}
