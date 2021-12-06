/*

    It seems like the year of 2013 came only yesterday. Do you know a curious fact? The year of 2013 is the first year after the old 1987 with only distinct digits.

    Now you are suggested to solve the following problem: given a year number, find the minimum year number which is strictly larger than the given one and has only distinct digits.
Input

    The single line contains integer y (1000 ≤ y ≤ 9000) — the year number.
Output

    Print a single integer — the minimum year number that is strictly larger than y and all it's digits are distinct. It is guaranteed that the answer exists.
*/

#include<stdio.h>
int main()
{
    int i,j,n,copy_n;   ///only for 4digit especial,make a every digit.........
    int rem1,rem2,rem3,rem4;
    scanf("%d",&n);
    while(1)
    {
        n++;
        copy_n=n;
        rem1=copy_n%10;
        copy_n=copy_n/10;
        rem2=copy_n%10;
        copy_n=copy_n/10;
        rem3=copy_n%10;
        copy_n=copy_n/10;
        rem4=copy_n;
        if(rem1!=rem2 && rem1!=rem3 && rem1!=rem4 && rem2!=rem3 && rem2!=rem4 && rem3!=rem4)  //the infinity loop only will break,
           break;                                                                                   //when all remainder will be distinct


    }
    printf("%d\n",n);
    return 0;
}
