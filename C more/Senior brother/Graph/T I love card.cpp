#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,arr[2][12],n1,n2;

    queue<int>player1,player2;
    scanf("%d",&n);

    scanf("%d",&n1);
    for(i=0;i<n1;i++){
        scanf("%d",&val);
        player1.push(val);
    }
    scanf("%d",&n2);
    for(i=0;i<n2;i++){
        scanf("%d",&val);
        player2.push(val);
    }

    while(!player1.empty() && !player2.empty()){
        int m=player1.front();
        int n=player2.front();
        player1.pop(); player2.pop();

        if(m>n){
            player1.push(n);
            player1.push(m);
        }

        else{
            player2.push(m);
            player2.push(n);
        }
        t++;
        if(t>400)break;
    }
    if(t>400) printf("-1\n");
    else if(player1.empty())   printf("%d %d\n",t,2);
    else   printf("%d %d\n",t,1);


    //free();   //if pointer array
    return 0;
}
