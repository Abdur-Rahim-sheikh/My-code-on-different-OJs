#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    char ch;
    cin>>test;
    while(test--){
        scanf("%d %d %d",&n,&m,&k);
        bool stupid[n+5];
        int maxi=k;

        for(i=1;i<=n;i++){
            scanf(" %c",&ch);
            if(ch=='S')stupid[i]=true;
            else stupid[i]=false;
        }
        for(i=0,cnt=0;i<m;i++){

           scanf("%*c%c",&ch);
           if(ch == 'W'){
                scanf("%d",&val);
                if(val>maxi){
                    maxi=val;
                }
                else if(stupid[val]==true){
                    cnt++;
                }
           }
           else maxi=n;


        }
        printf("%d\n",cnt);
    }
    //free();   //if pointer array
    return 0;
}
