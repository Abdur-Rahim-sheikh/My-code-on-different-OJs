/**You have a string of lowercase English alphabetic letters. You can perform two types of operations on the string:

    Append a lowercase English alphabetic letter to the end of the string.
    Delete the last character in the string. Performing this operation on an empty string results in an empty string.

Given an integer, , and two strings, and , determine whether or not you can convert to by performing exactly of the above operations on . If it's possible, print Yes. Otherwise, print No.

For example, strings and . Our number of moves, . To convert to , we first delete all of the characters in moves. Next we add each of the characters of in order. On the move, you will have the matching string. If there had been more moves available, they could have been eliminated by performing multiple deletions on an empty string. If there were fewer than moves, we would not have succeeded in creating the new string.

Input Format

The first line contains a string ,s the initial string.
The second line contains a string ,t the desired final string.
The third line contains an integer ,n the number of operations.

algorithm
1)find how many character left from 1st string after matching with second string
  continously(rem)
2)find the differece of two string 2nd-1st=difference
NOtE:difference will never be negetive if reminder is positive....
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    long long int i,j,k,m,n,rem,div,size1,size2,difference;
    char compare[105],with[105];

    size1=strlen(gets(compare));

    size2=strlen(gets(with));

    for(i=0;i<size1 && i<size2;i++)
    {
        if(compare[i]!=with[i])
            break;
    }

    rem=size1-i;                    //to make remainder 0 the second string must be equal or greater then first string
    difference=size2-size1;

    scanf("%lld",&n);

    if(rem*2+difference<=n)          //if diff is positive it will increase left side

        printf("Yes\n");            //or it will decrease left side which is needed.
    else
        printf("No\n");

    return 0;
}
