#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;
int parent[100005];
int total[100005];
int find_parent(int val){
    if(parent[val]==val)return val;
    parent[val]=find_parent(parent[val]);
    return parent[val];

}
void unite(int a,int b){
    a=find_parent(a);
    b=find_parent(b);
    if(a==b)return;
    total[a]+=total[b];
    parent[b]=a;
    return;
}
int main()
{

    int i,j,k,m,n,val,cnt,q;

    //freopen("000input.txt","r",stdin);
    cin>>n>>q;
    string ch;
    for(i=1;i<=n;i++)parent[i]=i,total[i]=1;

    for(i=0;i<q;i++){
        cin>>ch>>j;

        if(ch=="Q"){
            int papa=find_parent(j);
            printf("%d\n",total[papa]);
        }
        else{
            scanf("%d",&k);
            unite(j,k);
        }
    }
    //free();   //if pointer array
    return 0;
}
