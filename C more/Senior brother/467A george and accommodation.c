/*



    George has recently entered the BSUCP (Berland State University for Cool Programmers). George has a friend Alex who has also entered the university. Now they are moving into a dormitory.

    George and Alex want to live in the same room. The dormitory has n rooms in total. At the moment the i-th room has pi people living in it and the room can accommodate qi people in total (pi ≤ qi). Your task is to count how many rooms has free place for both George and Alex.
Input

    The first line contains a single integer n (1 ≤ n ≤ 100) — the number of rooms.

    The i-th of the next n lines contains two integers pi and qi (0 ≤ pi ≤ qi ≤ 100) — the number of people who already live in the i-th room and the room's capacity.
Output

    Print a single integer — the number of rooms where George and Alex can move in.
*/

#include<stdio.h>
int main()
{
        int n,i,j,sum1=0,sum2=0,sum3=0,x,y;
    scanf("%d",&n);
    for(i=0,j=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        if((y-x)>=2)
        {
            j++;
        }
    }
    printf("%d\n",j);
    return 0;
}
