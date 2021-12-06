#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<map>
#include<queue>
#include <sstream>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

string word[300];

vector<int> relates[300];
queue<int> serial;
int level[300];
bool checked[300];

map<string,int> number;
int BFS(int start,int dest);
int main()
{

    int i,j,k,m,n,val,t,total,test;
    string left,right,tem;

    cin>>test;
    while(test--){
            total=0;
        while(1){
            cin>>tem;

            if(tem=="*") break;
            word[total]=tem;
            number[tem]=total;
            total++;
        }


        for(i=0;i<total;i++){
                int lenI=word[i].length();
            for(j=0;j<total;j++){
                int lenJ=word[j].length();

                 if(lenI!=lenJ || i==j)
                        continue;

                 for(k=0,t=0;k<lenI;k++){
                    if(word[j][k]!=word[i][k])t++;
                 }
                 if(t==1){
                    relates[i].push_back(j);
                    relates[j].push_back(i);
                }
            }
        }
         cin.ignore();
        string line;
        while(getline(cin, line) && line != ""){
            stringstream ss(line);
            ss >> left >> right;
           // cin>>left>>right;
            cout<<left<<' '<<right<<' '<<BFS(number[left],number[right])<<endl;

            for(i=0;i<total;i++){
                level[i]=0;
                checked[i]=false;
            }

        }
        for(i=0;i<total;i++) relates[i].clear();

       if(test>0) printf("\n");

    }
    //free();   //if pointer array
    return 0;
}


int BFS(int start,int dest){
    checked[start]=true;
    level[start]=0;
    serial.push(start);
    while(!serial.empty()){
        int n=serial.front();
        serial.pop();
        int len=relates[n].size();

        for(int i=0;i<len;i++){
            int val=relates[n][i];


            if(checked[val]==false){
                checked[val]=true;
                serial.push(val);
                level[val]=level[n]+1;


                if(word[val]==word[dest]){
                    while(!serial.empty())serial.pop();
                    return level[val];
                }
            }
        }
    }
    return 0;
}

