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

//a=0,b=1,.............r=17,,,,,,,,z=25 is the technique as all first alphabet are unique.
//vector<int>city[10000];
map<string,bool>checked;

map<string,int>lvl;


int roadline(string surc,string ending,map<string,vector<string> >city);
int main()
{

    int i,j,k,m,n,val,t=0,test;
    string name1,name2;

    while(scanf("%d",&n)==1){

       map< string,vector<string> > city;
        for(i=0;i<n;i++){
            cin>>name1>>name2;



            city[name1].push_back(name2);
            city[name2].push_back(name1);
            checked[name1]=false;
            checked[name2]=false;

        }

        cin>>name1>>name2;



        ///start point.
       string  now=name1;

        if(city[name1].size()==0 || city[name2].size()==0) printf("No route\n");
        //printf("%c",now+'A');
        //cout<<lvl[now]<<'#'<<endl;
       else if(roadline(name2,name1,city)) while(lvl[now]!=1){
                cout<<now<<' ';
            int len=city[now].size();
            for(j=0;j<len;j++){
                    string val=city[now][j];
                if(lvl[val]==(lvl[now]-1)){
                   // printf("%c",val+'A');
                   cout<<val<<endl;
                    now=val;
                       break;
                }
            }
        }
        else printf("No route\n");

        printf("\n");
        ///referesher


    }
    //free();   //if pointer array
    return 0;
}

int roadline(string surc,string ending,map< string,vector<string> >city){
    queue<string> edge;
    checked[surc]=true;
    lvl[surc]=1;
    edge.push(surc);
    while(!edge.empty()){
        string n=edge.front();

        edge.pop();
        if(n==ending)  return 1;

        int len=city[n].size();
        for(int i=0;i<len;i++){
            string k=city[n][i];

            if(checked[k]==false){
                    edge.push(k);
                checked[k]=true;

                lvl[k]=lvl[n]+1;

               // printf("%c %d\n",k+'A',lvl[k]);

            }

        }

    }
    return 0;

}

