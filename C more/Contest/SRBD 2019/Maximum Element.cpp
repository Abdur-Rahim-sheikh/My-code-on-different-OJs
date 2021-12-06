#include<bits/stdc++.h>

#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;

class seg_tree{
    int *tree,*prop,*maxi,n;
    int low = -100000000;
	int INF=123456789;
    ///parameter
    ///update(1, 1, array_size, from_ind, to_ind, to_add_value)
    ///sum(1, 1, array_size, from_ind, to_ind,0)///last 0 for carry
public:
    seg_tree(int t){
        tree = new int[4*t];
        prop = new int[4*t];
        maxi = new int[4*t];

		fill(tree,tree+(4*t),0);
		fill(prop,prop+(4*t),0);
        n=t;
    }
public:
    ///update i to j with x if u want to update a single give i and j equal
    void update(int ind,int b,int e,int i,int j,int x){

        if(b>j || e<i)return;
        else if(b>=i && e<=j){
            maxi[ind]+=x;
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
        maxi[ind]=max(maxi[left],maxi[right]);
    }
    int maximum(int ind,int b,int e,int i,int j){
        if(b>j || e<i)return 0;
        else if(b>=i && e<=j)return maxi[ind];
        int left = ind*2;
        int right = ind*2+1;
        int mid = (b+e)/2;
       int ans1= maximum(left,b,mid,i,j);
       int ans2= maximum(right,mid+1,e,i,j);
        return max(ans1,ans2);
    }

};

int main()
{

    int i,j,k,m,n,val,total,cnt,test,sign;

    //freopen("000input.txt","r",stdin);

    cin>>n;
    seg_tree tree(n);
    total=0;
    int arr[n+5];
    for(i=0;i<n;i++){
        scanf("%d",&sign);
        if(sign==1){

            scanf("%d",&val);
            total++;
            arr[total]=val;
            tree.update(1,1,n,total,total,val);
        }
        else if(sign==2){
            tree.update(1,1,n,total,total,-arr[total]);
            total--;
        }
        else printf("%d\n",tree.maximum(1,1,n,1,total));

    }



    //free();   //if pointer array
    return 0;
}
