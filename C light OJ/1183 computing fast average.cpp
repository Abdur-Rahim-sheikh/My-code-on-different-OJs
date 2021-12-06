#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
ll gcd(ll a,ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

class seg_tree{
    int *prop,*time,*tree,n;

    ///parameter
    ///update(1, 1, array_size, from_ind, to_ind, to_add_value)
    ///sum(1, 1, array_size, from_ind, to_ind,0)///last 0 for carry
public:
    seg_tree(int t){
        prop = new int [4*t];
        tree = new int[4*t];

        fill(prop,prop+(4*t),-1);

        fill(tree,tree+(4*t),0);
        n=t;
    }
private:
    void propagate(int ind,int b,int e){
        int left=2*ind;
        int right=2*ind+1;
        int mid=(b+e)/2;

        prop[left]=prop[right]=prop[ind];
        tree[left]=(mid-b+1)*prop[ind];
        tree[right]=(e-mid)*prop[ind];
        prop[ind]=-1;

    }
public:
    ///update i to j with x if u want to update a single give i and j equal
    void update(int ind,int b,int e,int i,int j,int x){

        if(b>j || e<i)return;
        else if(b>=i && e<=j){
            //mini[ind]+=x;
            prop[ind]=x;
            tree[ind]=x*(e-b+1);
            return;
        }

        if(prop[ind]>(-1))propagate(ind,b,e);
        int left=2*ind;
        int right=2*ind+1;
        int mid=(b+e)/2;

        update(left,b,mid,i,j,x);
        update(right,mid+1,e,i,j,x);

        tree[ind]=tree[left]+tree[right];
        //mini[ind]=min(mini[left],mini[right]);
    }
    ///always initial ind & b is 1 ,e is n && carry is 0
    ll sum(int ind,int b,int e,int i,int j){

        if(b>j || e<i)return 0;
        else if(b>=i && e<=j){
            return tree[ind];
        }

        if(prop[ind]>(-1))propagate(ind,b,e);

        int left = 2*ind;
        int right =2*ind+1;
        int mid=(b+e)/2;
        ll ans1,ans2;

        ans1 = sum(left,b,mid,i,j);
        ans2 = sum(right,mid+1,e,i,j);

        return ans1+ans2;
    }

};

int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,sign;

    //freopen("000input.txt","r",stdin);

    cin>>test;

    while(test--){
        scanf("%d %d",&n,&m);
        seg_tree tree(n);
        printf("Case %d:\n",++t);
        for(k=1;k<=m;k++){
            scanf("%d %d %d",&sign,&i,&j);
            i++;
            j++;
            if(sign==1){
                scanf("%d",&val);
                tree.update(1,1,n,i,j,val);

            }
            else{
                ll ans = tree.sum(1,1,n,i,j);

                if(ans%(ll)(j-i+1)==0)printf("%lld\n",ans/(ll)(j-i+1));
                else{
                    ll gc=gcd(ans,(ll)(j-i+1));
                    printf("%lld/%lld\n",ans/gc,(j-i+1)/gc);
                }
            }
        }

    }



    //free();   //if pointer array
    return 0;
}
