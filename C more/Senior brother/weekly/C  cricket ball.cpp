#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
#define ll long long
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test,val_l,cnt=0;
    string str[10];
    cin>>test;
    getchar();
    while(test--){
        for(i=0;i<5;i++)
            cin>>str[i];
        for(i=0;i<5;i++){


            if(str[i].find('<')!=string::npos){
                val=str[i].find('<');

                val_l=str[i].find('|');
                if(val_l>val)
                    printf("Case %d: No Ball\n",++cnt);
                else printf("Case %d: Thik Ball\n",++cnt);


            }

            else if(str[i].find('>')!=string::npos){
                 val=str[i].find('>');

                   val_l=str[i].find('|');
                  if(val_l<val)
                    printf("Case %d: No Ball\n",++cnt);
                else printf("Case %d: Thik Ball\n",++cnt);


            }


        }

    }

    //free();   //if pointer array
    return 0;
}
