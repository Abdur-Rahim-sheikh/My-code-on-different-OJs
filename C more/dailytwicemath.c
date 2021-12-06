//the famouse tric,jekhane bebosayi nirdisto dine taka double er prokriyay onek taka hatie nie jae.

#include<stdio.h>
int main()
{
	int i,n,day;
	float magic,magic1,sum,difference,samevalue;
	printf("GIve the day limit you want to continue your business=");
	scanf("%d",&n);

	printf("give initial value which will twice(tk):");
	scanf("%f",&magic);

	printf("give initial value which will remain same(tk):");
	scanf("%f",&samevalue);

	magic1=magic;
	for(day=2;day<=n;day++)
	{
		magic=magic*2;
		sum=sum+magic;
	}
	difference=magic1+sum-(n*samevalue);

	if(n==0)
        printf("NO money transfered because day 0\n");
    else if(difference>0)
        printf("businessman will make profit %f in %d days.\nAt the last day (%d) he will get %f taka\n",difference,n,n,magic);
    else if(difference<0)
        printf("businessman will loss %f in %d days.\nAt the last day (%d) he will get %f taka\n",difference,n,n,magic);
    else
        printf("NO loss no profit for businessman cause given and taken money is equal\n");
    return 0;
}
