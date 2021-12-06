#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test,sum;

    string a;
    cin>>a;
    n=a.length();
    if(a[0]-'a'>13)
            sum=(26-(a[0]-'a'));
    else    sum=(a[0]-'a');
    for(i=1;i<n;i++)
    {
        if(abs(a[i]-a[i-1])>13)
            sum+=(26-abs(a[i]-a[i-1]));
        else    sum+=abs(a[i]-a[i-1]);
        //cout<<sum<<endl;
    }
    printf("%d\n",sum);
    //free();   //if pointer array
    return 0;
}
