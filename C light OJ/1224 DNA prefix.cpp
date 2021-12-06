#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
typedef struct Node node;
struct Node{
    int cnt=0;
    node *acg[5];
    Node(){
        for(int i=0;i<4;i++){
            acg[i]=NULL;
        }

    }

};
void del(node *cur){

   /// if(!node)return;/// no need
    for(int i=0;i<4;i++){
        if(cur->acg[i])del(cur->acg[i]);

    }
    delete(cur);
}
int creat(node *root,string &a);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);

    cin>>test;
    string a;
    while(test--){
        scanf("%d",&n);
        node *root = new Node();
        int high,prev=0;
        for(i=0;i<n;i++){
            cin>>a;
            high=creat(root,a);
            prev=max(prev,high);
        }
        printf("Case %d: %d\n",++t,prev);
        del(root);

    }



    //free();   //if pointer array
    return 0;
}

int creat(node *root,string &a){

    node *cur=root;
    int len=a.size(),val,prev=0;
    for(int i=0;i<len;i++){
        if(a[i]=='A')val=0;
        else if(a[i]=='C')val=1;
        else if(a[i]=='G')val=2;
        else val=3;
        if(cur->acg[val]==NULL){
            cur->acg[val] = new Node();
        }
        cur = cur->acg[val];

        cur->cnt++;
        prev=max(prev,(i+1)*cur->cnt);
    }
    return prev;


}
