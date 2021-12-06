/*

    Little Petya very much likes gifts. Recently he has received a new laptop as a New Year gift from his mother. He immediately decided to give it to somebody else as what can be more pleasant than giving somebody gifts. And on this occasion he organized a New Year party at his place and invited n his friends there.

    If there's one thing Petya likes more that receiving gifts, that's watching others giving gifts to somebody else. Thus, he safely hid the laptop until the next New Year and made up his mind to watch his friends exchanging gifts while he does not participate in the process. He numbered all his friends with integers from 1 to n. Petya remembered that a friend number i gave a gift to a friend number pi. He also remembered that each of his friends received exactly one gift.

    Now Petya wants to know for each friend i the number of a friend who has given him a gift.
Input

    The first line contains one integer n (1 ≤ n ≤ 100) — the quantity of friends Petya invited to the party. The second line contains n space-separated integers: the i-th number is pi — the number of a friend who gave a gift to friend number i. It is guaranteed that each friend received exactly one gift. It is possible that some friends do not share Petya's ideas of giving gifts to somebody else. Those friends gave the gifts to themselves.
Output

    Print n space-separated integers: the i-th number should equal the number of the friend who gave a gift to friend number i.
*/

#include<stdio.h>
int main()
{
    int i,n,j,k,in[100],out[100];
    scanf("%d",&n);                                                                 //if n=3
    for(i=0;i<n;i++)
    {
        scanf("%d",&in[i]);                                                           //if 2 1 3 then in[0]=2,in[1]=1,in[2]=3
    }
    for(i=0;i<n;i++)
    {
        j=in[i];               //i'th index value will be in j                         j=2
        k=in[j-1];                //j-1 to adjust index,,,j'th index value will be k                         k=1
        out[k-1]=j;             //k-1 to adjust index,,,the value of j will be save in value if k'th index     out[0]=2
    }                      //so according to story 2 gave gift to 1 so in output index of to is in 1(1st) but according to index 1-1=0index
    for(k=0;k<n;k++)
    {
        printf("%d ",out[k]);
    }
    printf("\n");
    return 0;
}
