#include<bits/stdc++.h>

using namespace std;


class segtree{
    int *prop;
    set<int> distinct;
    void propagate(int ind){
        int l=ind*2;
        int r=ind*2+1;
        prop[l]=prop[ind];
        prop[r]=prop[ind];
        prop[ind]=0;

    }
    void solve(int ind,int b,int e){
        if(b==e){
            if(prop[ind]>0)distinct.insert(prop[ind]);
            //cout<<b<<' '<<prop[ind]<<endl;
            return;
        }
        int mid=(b+e)/2;
        int l=ind*2;
        int r=ind*2+1;

        if(prop[ind]>0)propagate(ind);
        solve(l,b,mid);
        solve(r,mid+1,e);
        return;

    }
public:
    segtree(int n){
        //tree = new int[4*n];
        prop = new int[4*n];
       // memset(tree,0,sizeof tree);
        fill(prop,prop+(4*n),0);
    }

    void update(int ind,int b,int e,int i,int j,int val){
        if(b>j || e<i)return;
        else if(b>=i && e<=j){
            prop[ind]=val;
            return;
        }
        int mid=(b+e)/2;
        int l=ind*2;
        int r=ind*2+1;
        if(prop[ind]>0)propagate(ind);
        update(l,b,mid,i,j,val);
        update(r,mid+1,e,i,j,val);
        return;
    }
    int get_dist(int b,int e){
        distinct.clear();
        solve(1,b,e);
        return distinct.size();

    }

};
int main(){

    int test,i,j,n,a,b,t=0;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%d",&n);

        segtree tree = segtree(2*n);
        for(i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            //cout<<a<<' '<<b<<endl;
            tree.update(1,1,2*n,a,b,i+1);
        }
        int ans=tree.get_dist(1,2*n);
        printf("Case %d: %d\n",++t,ans);
    }
}
