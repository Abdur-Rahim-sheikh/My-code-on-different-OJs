/*

    Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

    Petya calls a number almost lucky if it could be evenly divided by some lucky number. Help him find out if the given number n is almost lucky.
Input

    The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.
Output

    In the only line print "YES" (without the quotes), if number n is almost lucky. Otherwise, print "NO" (without the quotes).
*/

#include<stdio.h>
int main()
{
    int num,num1,rem,i,j,k=0,f=0;
    scanf("%d",&num);
    for(i=4;i<=num;i++)
    {
        rem=num%i;
        if(rem==0)
        {
            j=i;
            while(j>0)
            {                                      //for(k=0;j>0;k++)
                k++;
                rem=j%10;
                j=j/10;
                if(rem!=4 && rem!=7)
                       goto end;                    //???????????why goto statement don't working.
                if(rem==4 || rem==7)
                {
                    f++;
                }
                end:
            }


        }

    }
    if(k==f && k>0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
