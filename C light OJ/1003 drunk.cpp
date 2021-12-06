#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define pb push_back
using namespace std;

map<string,int> checked_lvl;

bool cycle;
queue<string>que;
void DFS(string node,map<string,vector<string> > &network);
int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test;
    string s1,s2;
    cin>>test;
    while(test--){
        scanf("%d",&n);
        map<string,vector<string>>alcohol;
        set<string> names;
        set<string>::iterator it;
        for(i=0;i<n;i++){
            cin>>s1>>s2;
            names.insert(s2);
            alcohol[s2].pb(s1);

        }
        it=names.begin();

        cycle =false;
        checked_lvl.clear();
        while(it!=names.end()){

           if(checked_lvl[*it] == 0){
                DFS(*it,alcohol);
            }

            if(cycle == true)break;

            it++;
       }

        if(cycle)printf("Case %d: No\n",++t);
        else printf("Case %d: Yes\n",++t);


    }

    //free();   //if pointer array
    return 0;
}


void DFS(string node,map<string,vector<string> > &network){
    checked_lvl[node]=1;
    for(string u: network[node]){

        if(checked_lvl[u] == 1){cycle =true ;return;}

        checked_lvl[u] = 1;

        DFS(u,network);


    }
    checked_lvl[node]=2;

}
