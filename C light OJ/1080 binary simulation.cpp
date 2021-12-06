#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
class segment_tree{
    int *tree,*prop,*minimum,*maximum,n;
    ///parameter
    ///update(1, 1, array_size, from_ind, to_ind, to_add_value)
    ///sum(1, 1, array_size, from_ind, to_ind,0)///last 0 for carry
public:
    segment_tree(int t){
        tree = new int[4*t+4];
        prop = new int [4*t+4];
        fill(tree,tree+(4*t+4),0);
        fill(prop,prop+(4*t+4),0);
        n=t;
    }

    ///update i to j with x if u want to update a single give i and j equal
    void update(int ind,int b,int e,int i,int j,int x){

        if(b>j || e<i)return;
        else if(b>=i && e<=j){
            tree[ind]+=x*(e-b+1);

            prop[ind]+=x;
            return;
        }
        int left=2*ind;
        int right=2*ind+1;
        int mid=(b+e)/2;
        update(left,b,mid,i,j,x);
        update(right,mid+1,e,i,j,x);
        tree[ind]=tree[left]+tree[right]+(e-b+1)*prop[ind];

    }
    ///here will not be given values (all arr binary)this update calls to inverse
    ///from i to j means if k = 0 then 1 if 1 then 0 (i<=k<=j)
     void inv_update(int ind,int b,int e,int i,int j){

        if(b>j || e<i)return;
        else if(b>=i && e<=j){
            prop[ind]^=1; ///ex-or operation to invert the values
            tree[ind]=(e-b+1) - tree[ind];  ///total range - previous total 1's so current one's.

            return;
        }
        int left=2*ind;
        int right=2*ind+1;
        int mid=(b+e)/2;
        inv_update(left,b,mid,i,j);
        inv_update(right,mid+1,e,i,j);

        if(prop[ind])tree[ind]=(e-b+1)-(tree[left]+tree[right]);
        else tree[ind]= tree[left]+tree[right];

    }
    ///always initial ind & b is 1 ,e is n && carry is 0
    ll inv_sum(int ind,int b,int e,int i,int j,int carry){

        if(b>j || e<i)return 0;
        else if(b>=i && e<=j)return tree[ind]^carry;

        int left = 2*ind;
        int right =2*ind+1;
        int mid=(b+e)/2;
        ll ans1 = inv_sum(left,b,mid,i,j,(carry^prop[ind]));
        ll ans2 = inv_sum(right,mid+1,e,i,j,(carry^prop[ind]));
        return ans1+ans2;

    }


};

int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    string a;
    while(test--){
        cin>>a;
        int n = a.size();
        segment_tree tree(n);

        for(i=0;i<n;i++){
            val= a[i]-'0';

            tree.update(1,1,n,i+1,i+1,val); ///first value 1th index

        }

        scanf("%d",&k);
        char ch;
        int l,r;
        printf("Case %d:\n",++t);

        for(i=0;i<k;i++){
            scanf("%*c%c %d",&ch,&l);

            if(ch=='I'){
                scanf("%d",&r);
                tree.inv_update(1,1,n,l,r);

            }
            else printf("%lld\n",tree.inv_sum(1,1,n,l,l,0));


        }

    }



    //free();   //if pointer array
    return 0;
}

