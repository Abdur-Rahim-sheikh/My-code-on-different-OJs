#include<stdio.h>

int main(){

    char array[200][200];
    int a,b,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",array[i]);
        printf("%s",array[i]);
    }
}