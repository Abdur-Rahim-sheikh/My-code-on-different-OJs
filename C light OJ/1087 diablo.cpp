#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;

class BIT{
    int *tree,n;
public:
    int arr[160000];
    BIT(int n){
        tree = new int[n+5];
        fill(tree,tree+n+5,0);
        fill(arr,arr+n+5,0);
        this->n=n+5;
    }
    void update(int i,int val){
        while(i<=n){
            tree[i]+=val;
            i+=(i&-i);
        }
    }
    int totalValidIndex(int i){
        int sum=0;
        while(i>0){
            sum+=tree[i];
            i-=(i&-i);
        }
        return sum;
    }
    int trueIndex(int ind,int total){
        int l=1,r=total,mid;
        while(l<=r){
            mid=(l+r)/2;
            int sum=totalValidIndex(mid);
            //cout<<l<<' '<<mid<<' '<<r<<' '<<sum<<' '<<ind<<endl;
            if(sum==ind && arr[mid]==1)break;
            else if(sum<ind)l=mid+1;
            else r=mid-1;
        }
        if(l<=r){
            arr[mid]=0;
            update(mid,-1);
            return mid;
        }
        else return INF;
    }
};
int main(){

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    char ch;
    while(test--){
        cin>>n>>m;
        BIT tree=BIT(n+m);
        int arr[n+m+5];
        for(k=1;k<=n;k++){
            scanf("%d",&arr[k]);
            tree.arr[k]=1;
            tree.update(k,1);
        }

        printf("Case %d:\n",++t);
        for(i=0;i<m;i++){
            scanf("%*c%c %d",&ch,&val);
            if(ch=='a'){
                tree.arr[k]=1;
                tree.update(k,1);
                arr[k++]=val;   ///Here val means id
            }
            else if(val>=k)printf("none\n");
            else{

                int left=tree.trueIndex(val,k-1);      ///here val means index
                //cout<<val<<' '<<left<<endl;
                if(left<k)printf("%d\n",arr[left]);
                else printf("none\n");
            }
        }
    }
    //free();   //if pointer array
    return 0;
}
