#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

//a=0,b=1,.............r=17,,,,,,,,z=25 is the technique as all first alphabet are unique.
vector<int>city[100];
bool checked[100];
queue<int> edge;
int lvl[100];

void roadline(int surc,int ending);
int main()
{

    int i,j,k,m,n,val,t=0,test;
    string name1,name2;
    cin>>test;
    while(test--){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            cin>>name1>>name2;
            city[name1[0]-'A'].push_back(name2[0]-'A');
            city[name2[0]-'A'].push_back(name1[0]-'A');

        }
       for(i=0;i<m;i++){
            cin>>name1>>name2;

            roadline(name2[0]-'A',name1[0]-'A');

            ///start point.
            int now=name1[0]-'A';

            printf("%c",now+'A');
            //cout<<lvl[now]<<'#'<<endl;
            while(lvl[now]!=1){
                int len=city[now].size();
                for(j=0;j<len;j++){
                        int val=city[now][j];
                    if(lvl[val]==(lvl[now]-1)){
                        printf("%c",val+'A');
                        now=val;
                        break;
                    }
                }
            }

            printf("\n");
            ///referesher
            for(j=0;j<30;j++){
                checked[j]=false;
                lvl[j]=0;
            }

       }
       for(int i=0;i<30;i++) city[i].clear();
       if(test>0)printf("\n");
    }
    //free();   //if pointer array
    return 0;
}

void roadline(int surc,int ending){
    checked[surc]=true;
    lvl[surc]=1;
    edge.push(surc);
    while(!edge.empty()){
        int n=edge.front();

        edge.pop();

        int len=city[n].size();
        for(int i=0;i<len;i++){
            int k=city[n][i];

            if(checked[k]==false){
                    edge.push(k);
                checked[k]=true;

                lvl[k]=lvl[n]+1;

               // printf("%c %d\n",k+'A',lvl[k]);
                if(k==ending){
                   while(!edge.empty()){
                    edge.pop();
                   }

                    return;
                }
            }

        }

    }

}

