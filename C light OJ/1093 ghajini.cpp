#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
int minimum[400000],maximum[400000];
void update(int ind,int b,int e,int i,int x){

    if(b>i || e<i)return;
    else if(b==e && b==i){
        maximum[ind]=minimum[ind]=x;
        return;
    }
    int left= 2*ind;
    int right=2*ind+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    maximum[ind]=max(maximum[left],maximum[right]);
    minimum[ind]=min(minimum[left],minimum[right]);

}

int mini(int ind,int b,int e,int i,int j){
    if(b>j || e<i)return INF;
    else if(b>=i && e<=j) return minimum[ind];

    int left= 2*ind;
    int right=2*ind+1;
    int mid = (b+e)/2;
    int ans1=mini(left,b,mid,i,j);
    int ans2=mini(right,mid+1,e,i,j);
    return min(ans1,ans2);


}

int maxi(int ind,int b,int e,int i,int j){
    if(b>j || e<i)return -1;
    else if(b>=i && e<=j) return maximum[ind];

    int left= 2*ind;
    int right=2*ind+1;
    int mid = (b+e)/2;
    int ans1=maxi(left,b,mid,i,j);
    int ans2=maxi(right,mid+1,e,i,j);
    return max(ans1,ans2);


}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);

    cin>>test;

    while(test--){
        scanf("%d %d",&n,&k);
        int dif=0;
        fill(minimum,minimum+(4*n),INF);
        fill(maximum,maximum+(4*n),-1);
        for(i=1;i<k;i++){
            scanf("%d",&val);
            update(1,1,n,i,val);
        }

        for( ;i<=n;i++){
            scanf("%d",&val);
            update(1,1,n,i,val);
            int ans1=mini(1,1,n,(i-k+1),i);
            int ans2=maxi(1,1,n,(i-k+1),i);


            dif=max(dif,ans2-ans1);
        }
        printf("Case %d: %d\n",++t,dif);
    }



    //free();   //if pointer array
    return 0;
}
