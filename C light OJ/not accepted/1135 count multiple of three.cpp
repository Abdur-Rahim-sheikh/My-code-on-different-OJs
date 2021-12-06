#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
int tree[3][400000],prop[400000];

class seg_tree{

    ///parameter
    ///update(1, 1, array_size, from_ind, to_ind, to_add_value)
    ///sum(1, 1, array_size, from_ind, to_ind,0)///last 0 for carry
public:
    seg_tree(int t)
    {
        fill(prop,prop+(4*t),0);
        fill(tree[0],tree[0]+(4*t),0);
        fill(tree[1],tree[1]+(4*t),0);
        fill(tree[2],tree[2]+(4*t),0);
        init(1,0,t-1);
    }
private: /// use it when it's needed with update and sum,carefully
    void propagate(int ind,int b,int e)
    {
        int left=2*ind;
        int right=2*ind+1;
        int mid=(b+e)/2;

        prop[left]=(prop[left]+prop[ind])%3;
        prop[right]=(prop[right]+prop[ind])%3;
        prop[ind]=0;

    }
    void init(int ind,int b,int e){
        if(b==e){
            tree[0][ind]=1;
            return;
        }
        init(ind*2,b,(b+e)/2);
        init(ind*2+1,((b+e)/2)+1,e);
        tree[0][ind]=(e-b)+1;
    }
public:
    ///update i to j with x if u want to update a single give i and j equal
    void update(int ind,int b,int e,int i,int j)
    {

        if(b>j || e<i)
            return;
        else if(b>=i && e<=j)
        {
            prop[ind]=(prop[ind]+1)%3;
            if(b==e){
                int k=prop[ind];
                tree[k][ind]=1;
                tree[(k+1)%3][ind]=tree[(k+2)%3][ind]=0;
                prop[ind]=0;
            }
            cout<<tree[0][ind]<<' '<<tree[1][ind]<<' '<<tree[2][ind]<<' '<<ind<<endl;
            return;
        }
        if(prop[ind]>0)
            propagate(ind,b,e);
        int left=2*ind;
        int right=2*ind+1;
        int mid=(b+e)/2;
        update(left,b,mid,i,j);
        update(right,mid+1,e,i,j);
        for(int i=0; i<3; i++)
        {
            int tem=(i+prop[left])%3;
            int tem2=(i+prop[right])%3;
            tree[i][ind]=tree[tem][left]+tree[tem2][right];
            cout<<tree[i][ind]<<' '<<prop[left]<<' '<<prop[right]<<endl;
        }
        cout<<ind<<" THIS"<<endl;
        //mini[ind]=min(mini[left],mini[right]);
    }
    ///always initial ind & b is 1 ,e is n && carry is 0
    ll sum(int ind,int b,int e,int i,int j)
    {

        if(b>j || e<i)
            return 0;
        else if(b>=i && e<=j)
        {

            return tree[prop[ind]][ind];
        }
        if(prop[ind]>0)
            propagate(ind,b,e);

        int left = 2*ind;
        int right =2*ind+1;
        int mid=(b+e)/2;
        ll ans1 = sum(left,b,mid,i,j);
        ll ans2 = sum(right,mid+1,e,i,j);
        return ans1+ans2;

    }

};

int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,sign;

    freopen("000input.txt", "r",stdin);

    cin>>test;

    while(test--)
    {
        scanf("%d %d",&n,&m);
        seg_tree tree =  seg_tree(n);
        printf("Case %d:\n",++t);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&sign,&j,&k);

            if(sign)
                printf("%lld alkjdsfakdj\n",tree.sum(1,0,n-1,j,k));
            else
                tree.update(1,0,n-1,j,k),cout<<endl;
        }

    }



    //free();   //if pointer array
    return 0;
}
