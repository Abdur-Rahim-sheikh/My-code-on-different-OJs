#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
typedef struct Alphanet alphanet;


struct Alphanet{
    bool endp=false;
    alphanet *alpha[12];
    Alphanet(){
        for(int i=0;i<10;i++) alpha[i]=NULL;
    }
};


bool creatAndCheck(alphanet *root,string &a);
void del(alphanet *node);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);

    cin>>test;
    string a;
    while(test--){
        scanf("%d",&n);
        alphanet *root = new Alphanet();
        bool ans=true;
        for(i=0;i<n;i++){
            cin>>a;
            bool cons=creatAndCheck(root,a);
            if(cons)ans=false;
        }
        if(ans)printf("Case %d: YES\n",++t);
        else printf("Case %d: NO\n",++t);

        del(root);
    }

    //free();   //if pointer array
    return 0;
}
bool creatAndCheck(alphanet *root,string &a){
    bool checker=true;
    alphanet *cur=root;
    int len =a.size();
    for(int i=0;i<len;i++){
        int val=a[i]-'0';
        if(cur->alpha[val]==NULL){
            cur->alpha[val] = new Alphanet();
            checker = false;
        }
        if(checker==true && cur->alpha[val]->endp==true)break;
        cur=cur->alpha[val];
    }
    cur->endp=true;
    return checker;
}
void del(alphanet *node){

    if(!node)return;
    for(int i=0;i<10;i++){
        if(node->alpha[i])del(node->alpha[i]);

    }
    delete(node);
}
