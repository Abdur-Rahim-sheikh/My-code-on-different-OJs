/*    A bird was flying on a train line, singing and passing lazy times. After a while it saw a train coming from its behind, so, it speeded up a bit, but remained calm. After a while it saw another train coming towards it from the front side. The bird remained calm thinking that the train coming towards him would be in another line. But after a while it realized that both the trains were on the same line!

    So, the stupid brave bird made a plan to stop the accident. So it flew towards the train which was coming from the front side, and after touching the train the bird turned back immediately, and flew until it could touch another train. And after that it turned back, and continued this procedure. The birds' intention was to signal the drivers such that they could stop the train.

    When the trains were d meter way, the drivers realized the abnormal behavior of the strange bird, and saw the opposite trains, and both drivers braked hard! But alas! They were able to stop the collision, but they managed to stop in front of each other leaving no distance. And the brave bird was dead in the middle of the trains. Thousand lives saved, but none remembered the bird.

    For simplicity we denote the train (that was behind the bird) as the left train and the other one as the right train. The left train had velocity v1 m/s (meter per second) and the right train had velocity v2 m/s and they saw each other when they were d meter away. The driver in the left train made a deceleration of a1 m/s2 and the driver in the right train made a deceleration of a2 m/s2. And the trains just avoided collision. That means they just stopped when their distance was 0 meter. The bird had constant velocity of v3 m/s. And assume that the bird can turn immediately and can keep its constant velocity. When the trains were d meter away, the bird was somewhere between the trains. Your task is to find the distance covered by the brave bird (from this moment) in meters before sacrificing its life for thousand lives.
Input

    Input starts with an integer T (≤ 100), denoting the number of test cases.

    Each case starts with a line containing five positive real numbers: v1 v2 v3 a1 a2 (v1 < v3, v2 < v3). No real number will be greater than 1000. And no number contains more than three digits after the decimal point.
Output

    For each case, print the case number, d and the distance covered by the bird. Errors less than 10-6 will be ignored.
*/
#include<stdio.h>
int main()
{
    int i,n;
    double v1,v2,v3,a1,a2,distance[100],covered_distance[100],max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);
        distance[i]=0.5*((v1*v1/a1)+(v2*v2/a2));   //

       max=v1/a1>v2/a2?v1/a1:v2/a2;

        covered_distance[i]=v3*max;
       // covered_distance[i]=distance[i]*v3;

    }
    for(i=0;i<n;i++)
    {
        printf("Case %d: %0.6lf %0.6lf\n",i+1,distance[i],covered_distance[i]);
    }
    return 0;
}
