#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test,arr[4000],sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int prev=arr[0];
    int highest=0;
    for(i=1;i<n;i++){
        if(arr[i]==prev)t++;
        else{
            ///calculate highest value,total value,this value.
            if(highest<prev){
                    sum+=(t*(t+1))/2;
                    highest=prev+t;
            }
            ///if highest is greater than current value.
            else{
                sum+=(t*(t+1))/2+((t+1)*(highest-prev+1));
                highest=highest+t+1;
            }

            ///cout<<sum<<' '<<highest<<' '<<prev<<endl;
            prev=arr[i];
            t=0;

        }
    }
    if(highest<prev){
        sum+=(t*(t+1))/2;
        highest=prev+t;
    }
    ///if highest is greater than current value.
    else{
        sum+=(t*(t+1))/2+((t+1)*(highest-prev+1));
        highest=highest+t+1;
    }

    printf("%d\n",sum);
    //free();   //if pointer array
    return 0;
}
