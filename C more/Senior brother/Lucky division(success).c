/*

    Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

    Petya calls a number almost lucky if it could be evenly divided by some lucky number. Help him find out if the given number n is almost lucky.
Input

    The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.
Output

    In the only line print "YES" (without the quotes), if number n is almost lucky. Otherwise, print "NO" (without the quotes).
*/


#include<stdio.h>        ///solving steps is in note.
int main()
{
    int num,num1,rem,i,j,k,f;
    scanf("%d",&num);
    for(i=4;i<=num;i++)           //the loop to divide num by 1 to num one by one.
    {
        rem=num%i;
        if(rem==0)               //this condition to cheek if i a multiplicand of num or not.
        {
            j=i;                  //copying i to j to save the value of i
            for(k=0,f=0;j>0;k++)  //the loop will seperate j which is actually i into individual digit.everytime we enter the loop the initial value of f and k will be zero,that's the key.
            {

                rem=j%10;
                j=j/10;
                if(rem==4 || rem==7)      //to cheek the digit if they are 4 or 7 or not
                {
                    f++;
                }
            }
        }
        if(k==f && k>0)         //to cheek if i only contain 4 and 7 digit
            break;

    }
    if(k==f && k>0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
