#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;
#define SWAP(a,b) { \
                    a^=b;\
                    b^=a;\
                    a^=b;\
}
struct valu{

        int val,num;
    }stu[100099];
int main()
{

    int a,b,i,j,k,m,n,val,t,q,test,left,right,here,there;
    scanf("%d",&test);
    for(q=0;q<test;q++){
            scanf("%d %d",&n,&m);
        for(i=0,t=0;i<n;i++){
            scanf("%d",&stu[i].val);
            stu[i].num=++t;

        }
        printf("Case %d:\n",q+1);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);

            for(j=0,left=-1,right=1e9;j<n;j++){
                if(stu[j].val<a){
                    left=j;

                }
                if(stu[j].val>b){
                    right=j;
                    break;
                }
            }
            here=left==-1?0:stu[left].num;
            there=right==1e9?stu[n-1].num:stu[right-1].num;
            printf("%d\n",there-here);
        }
    }

    //free();   //if pointer array
    return 0;
}


