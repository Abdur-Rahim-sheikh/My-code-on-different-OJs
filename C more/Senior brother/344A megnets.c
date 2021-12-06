#include<stdio.h>
int main()
{
   long long int n;
   int megnet,i,j=0,previous=0;
   scanf("%lld",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&megnet);
       if(megnet!=previous)
       {
           j++;
       }
       previous=megnet;
   }
   printf("%d\n",j);
   return 0;
}
