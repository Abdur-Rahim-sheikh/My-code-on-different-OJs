#include<iostream>
#define ll long long

using namespace std;

int main()
{

    int i,j,k,m,n,val,test;

    int lstd[10][10]={ {0},
                    {1,1,1,1},
                    {6,2,4,8},
                    {1,3,9,7},
                    {6,4,6,4},
                    {5,5,5,5},
                    {6,6,6,6},
                    {1,7,9,3},
                    {6,8,4,2},
                    {1,9,1,9}};


    cin>>test;
    while(test--){
            ll power;
        cin>>k>>power;

         k=k%10;
        if(k==0)printf("0\n");
        else if(power==0)printf("1\n");
        else  printf("%d\n",lstd[k][power%4]);

    }

    //free();   //if pointer array
    return 0;
}
