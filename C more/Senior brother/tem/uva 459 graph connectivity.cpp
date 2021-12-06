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
map<int,bool> checked;
void BFS(int start,vector<int>arr[]);
queue<int>que;
int main()
{

    int i,j,k,m,n,val,t,test;

    cin>>test;
    while(test--){
        vector<int>arr[500];

        string a,high;
        cin>>high;
        cin.ignore();

        while(getline(cin,a) && a!=""){
            arr[a[0]].push_back(a[1]);
            arr[a[1]].push_back(a[0]);

        }
        for(i='A',t=0;i<=high[0];i++){
            if(checked[i]==false){
                t++;
                BFS(i,arr);
            }
        }
        printf("%d\n",t);

        if(test>0)printf("\n");
        checked.clear();
    }
    //free();   //if pointer array
    return 0;
}

void BFS(int start,vector<int>arr[]){
    checked[start]=true;
    que.push(start);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=arr[n].size();
        for(int i=0;i<len;i++){
            int val=arr[n][i];
            if(checked[val]==false){
                checked[val]=true;
                que.push(val);
            }
        }
    }

}

