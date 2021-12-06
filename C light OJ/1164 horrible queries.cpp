#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
ll tree[400000],prop[400000];
void update(int ind,int b,int e,int i,int j,int x);
ll sum(int ind,int b,int e,int i,int j,int carry);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,sign,q;

    //freopen("000input.txt","r",stdin);

    cin>>test;

    while(test--){
        scanf("%d %d",&n,&q);
        fill(tree,tree+(4*n),0);
        fill(prop,prop+(4*n),0);
        printf("Case %d:\n",++t);
        for(i=0;i<q;i++){
            scanf("%d %d %d",&sign,&j,&k);
            j+=1;
            k+=1;
            if(sign) printf("%lld\n",sum(1,1,n,j,k,0));
            else{
                scanf("%d",&val);
                update(1,1,n,j,k,val);
            }
        }
    }



    //free();   //if pointer array
    return 0;
}

void update(int ind,int b,int e,int i,int j,int x){

    if(b>j || e<i)return;
    else if(b>=i && e<=j){
        prop[ind]+=x;
        tree[ind]+=(e-b+1)*x;
        return;
    }
    int left=2*ind;
    int right=2*ind+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[ind]=tree[left]+tree[right]+(ll)(e-b+1)*prop[ind];

}
ll sum(int ind,int b,int e,int i,int j,int carry){
    if(b>j || e<i)return 0;
    else if(b>=i && e<=j)  return tree[ind]+(ll)carry*(e-b+1);

    int left=2*ind;
    int right=2*ind+1;
    int mid=(b+e)/2;
    ll ans1=sum(left,b,mid,i,j,carry+prop[ind]);
    ll ans2=sum(right,mid+1,e,i,j,carry+prop[ind]);
    return ans1+ans2;

}
