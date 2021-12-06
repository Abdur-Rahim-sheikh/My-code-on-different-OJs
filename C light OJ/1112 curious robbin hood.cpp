#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
int tree[200000];
void update_tree(int i,int total,int val);
ll tree_sum(int i);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,ind,ind2;
    ll sum;
    cin>>test;
    while(test--){
        scanf("%d %d",&n,&m);
        int arr[n+5];
        for(i=1;i<=n;i++)tree[i]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&arr[i]);
            update_tree(i,n,arr[i]);
        }
        printf("Case %d:\n",++t);

        for(i=0;i<m;i++){
            scanf("%d %d",&k,&ind);
            ind = ind+1;        ///cause we are calculating one indexed array and input is for zero indexed array
            if(k == 1){
                update_tree(ind,n,-arr[ind]);
                printf("%d\n",arr[ind]);
                arr[ind]=0;
            }
            else if(k == 2){
                scanf("%d",&val);
                update_tree(ind,n,val);
                arr[ind]+=val;
            }
            else /// means k==3
            {

                scanf("%d",&ind2);
                ind2+=1;
                sum = tree_sum(ind2);
                sum=sum - tree_sum(ind-1);
                printf("%lld\n",sum);
            }
        }
    }




    //free();   //if pointer array
    return 0;
}
void update_tree(int i,int total,int val){
    while(i<=total){
        tree[i]+=val;
        i+=(i&-i);

    }

    return;
}

ll tree_sum(int i){

    ll sum=0;
    while(i>=1){
        sum+=tree[i];
        i-=(i&-i);
    }
    return sum;
}
