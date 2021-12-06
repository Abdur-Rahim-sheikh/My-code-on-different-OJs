#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
class seg_tree{
    int *tree,*prop,*mini,*maxi,n;
    int inf = 1073741824;
    ///parameter
    ///update(1, 1, array_size, from_ind, to_ind, to_add_value)
    ///sum(1, 1, array_size, from_ind, to_ind,0)///last 0 for carry
public:
    seg_tree(int t){
        mini = new int[4*t];
        fill(mini,mini+(4*t),0);
    }

    ///update i to j with x if u want to update a single give i and j equal
    void update(int ind,int b,int e,int i,int j,int x){

        if(b>j || e<i)return;
        else if(b>=i && e<=j){
            mini[ind]+=x;
            return;
        }
        int left=2*ind;
        int right=2*ind+1;
        int mid=(b+e)/2;
        update(left,b,mid,i,j,x);
        update(right,mid+1,e,i,j,x);
        //tree[ind]=tree[left]+tree[right]+(e-b+1)*prop[ind];
        mini[ind]=min(mini[left],mini[right]);
    }

    int minimum(int ind,int b,int e,int i,int j){
        if(b>j || e<i)return inf;
        else if(b>=i && e<=j)return mini[ind];
        int left = ind*2;
        int right = ind*2+1;
        int mid = (b+e)/2;
       int ans1= minimum(left,b,mid,i,j);
       int ans2= minimum(right,mid+1,e,i,j);
        return min(ans1,ans2);
    }

};

int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);

    cin>>test;

    while(test--){
        scanf("%d %d",&n,&k);
        seg_tree tree(n);
        for(i=1;i<=n;i++){
            scanf("%d",&val);
            tree.update(1,1,n,i,i,val);
        }
        printf("Case %d:\n",++t);
        for(i=0;i<k;i++){
            scanf("%d %d",&j,&m);
            printf("%d\n",tree.minimum(1,1,n,j,m));
        }

    }



    //free();   //if pointer array
    return 0;
}
