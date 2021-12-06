#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
 struct theif{
        int arr,k;
        char ch;
    }stu[50000];
bool small(theif a,theif b){return a.arr<b.arr;}
int main()
{

    char ch;
    int i,j,k,m,n,val,t=0,test,cnt,total;
    int arr[100000];
    cin>>test;

    while(test--){
        scanf("%d",&n);

        for(i=0,cnt=0,val=0;i<n;i++){
            scanf("%d %d %c",&stu[i].arr,&stu[i].k,&stu[i].ch);

            if(stu[i].arr>val && stu[i].k==1 && stu[i].ch=='c')val=stu[i].arr;

        }
        sort(stu,stu+n,small);
        for(i=0;stu[i].arr<val;i++){

           if(stu[i].arr<val && stu[i].k==0 && stu[i].ch=='i')
            break;
        }
        if(stu[i].arr>=val) printf("0\n");
        else printf("%d\n",n-i);

        //cout<<val;

    }
    //free();   //if pointer array
    return 0;
}
