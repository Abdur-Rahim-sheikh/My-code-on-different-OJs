#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i=0,j=0,k,n;
    long long int worker_value[1000],number[1000],lv1,lv2,lv3;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&worker_value[i]);
    }
    for(i=0;i<n;i++){
        scanf("%lld",&number[i]);
        if(number[i]==1)
            lv1=worker_value[i];
        else if(number[i]==2)
            lv2=worker_value[i];
        else
            lv3=worker_value[i];
    }
    for(i=0;i<n;i++)
    {
        if(number[i]==1 && worker_value[i]<lv1)
            lv1=worker_value[i];
        else if(number[i]==2 && worker_value[i]<lv2)
            lv2=worker_value[i];
        else if(number[i]==3 && worker_value[i]<lv3)
            lv3=worker_value[i];
    }
    if(lv1+lv2<lv3)
        printf("%lld\n",lv1+lv2);
    else
        printf("%lld\n",lv3);
    return 0;
}
