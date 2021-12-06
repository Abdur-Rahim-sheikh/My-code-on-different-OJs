#include<bits/stdc++.h>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test;
    //string str;
    cin>>test;
    while(test--){
        scanf("%d",&n);
        int total=0,sum=0;
        struct ring{

            int line[3],value[3];
            int cnt=0;
        }stu[n+5];
        for(i=0;i<n;i++){
            scanf("%d %d %d",&k,&m,&val);
            stu[k].line[stu[k].cnt]=m;
            stu[k].value[stu[k].cnt]=val;
            stu[k].cnt++;
            total+=val;
        }

        for(i=0;i<n;i++){
            if(stu[k].cnt==2){
                int val1=stu[k].line[0];
                int val2=stu[k].line[1];
                if(stu[val1].line[0]>0){
                    sum+=stu[k].value[1];
                    k=stu[k].line[0];
                }
                else{
                    sum+=stu[k].value[0];
                    k=stu[k].line[1];
                }
            }
            else k=stu[k].line[0];
        }
        printf("Case %d: %d\n",++t,sum);
    }

    //free();   //if pointer array
    return 0;
}
