#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val1,val2,t=0,test;
    string exact,given;
    cin>>test;
    getchar();
    while(test--){
        cin>>exact>>given;
        val1=exact.length();
        val2=given.length();
        if(exact==given){
            printf("Case %d: Login successful.\n",++t);
            continue;
        }
        if(val1<val2){
                printf("Case %d: Wrong password.\n",++t);
                continue;
        }
        if(val1==val2){
            for(i=0;i<val1;i++){
                 if((exact[i]<'0' || exact[i]>'9') && abs(exact[i]-given[i])!=32) break;
                 else if((exact[i]>='0' && exact[i]<='9') && exact[i]-given[i]!=0) break;
            }
            if(i==val1){
                printf("Case %d: Wrong password. Please, check your caps lock key.\n",++t);
               continue;
            }

        }
        int cnt=0;
        for(i=0;i<val1;i++){
            if(exact[i]>='0' && exact[i]<='9')
                continue;
            if(exact[i]!=given[cnt++])
                break;
        }
        if(i==val1 && cnt==val2)
        {
            printf("Case %d: Wrong password. Please, check your num lock key.\n",++t);
            continue;
        }
        for(i=0,cnt=0;i<val1;i++){
            if(exact[i]>='0' && exact[i]<='9')
                continue;
            if(abs(exact[i]-given[cnt++])!=32) break;
        }
        if(i==val1 &&cnt==val2) {
            printf("Case %d: Wrong password. Please, check your caps lock and num lock keys.\n",++t);

        }
        else printf("Case %d: Wrong password.\n",++t);
    }

    //free();   //if pointer array
    return 0;
}
