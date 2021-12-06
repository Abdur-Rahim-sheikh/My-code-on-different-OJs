#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
int tree[100005],n;
void update(int i,int j){
    while(i<=n){
        tree[i]+=1;
        i+=(i&-i);
    }
    j++;
    while(j<n){
        tree[j]-=1;
        j+=(j&-j);
    }
    return;
}

int query(int x){
    int sum=0;
    while(x>0){
        sum+=tree[x];
        x-=(x&-x);
    }
    return sum;
}
int main()
{

    int i,j,k,m,val,t=0,cnt,test;

    freopen("000input.txt","r",stdin);
    cin>>test;
    string a;
    while(test--){
        cin>>a;
        n=a.size();
        memset(tree,0,sizeof tree);
        scanf("%d",&k);
        char ch;

        int l,r;
        printf("Case %d:\n",++t);

        for(i=0;i<k;i++){
            scanf("%*c%c %d",&ch,&l);

            if(ch=='I'){
                scanf("%d",&r);
                update(l,r);
            }
            else{
                int total_inv=query(l);
                int ans=(a[l-1]-'0')^(total_inv%2);
                printf("%d\n",ans);
            }
        }

    }



    //free();   //if pointer array
    return 0;
}

