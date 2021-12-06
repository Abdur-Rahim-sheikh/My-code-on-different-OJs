#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test,prev=INF;
    size_t x;
    string in,b,a[]={"Danil", "Olya", "Slava", "Ann","Nikita"};
    cin>>b;
    for(i=0;i<5;i++){
        x=b.find(a[i]);
        if(x!=string::npos && x<prev)in=a[i],prev=x,cnt=1;
    }



    if(cnt){
        x=prev+1;
        for(j=0,t=0;j<5;j++){
            int p=b.find(a[j],x);

            //cout<<b[x]<<' '<<a[j]<<' '<<b<<endl;
            if(p==string::npos)t++;

        }
    }

    printf("%s\n",(t==5)?"YES":"NO");
    //free();   //if pointer array
    return 0;
}

