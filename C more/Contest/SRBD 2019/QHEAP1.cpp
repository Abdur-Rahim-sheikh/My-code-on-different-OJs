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
int heap[100005],heap_size=0;
void min_heapify(int i){

    int l=i*2,r=i*2+1,lowest=i,t;
    if(l<=heap_size && heap[l]<heap[lowest])lowest=l;
    if(r <= heap_size && heap[r]<heap[lowest])lowest =r;

    if(lowest !=i){
        t =heap[i];
        heap[i]=heap[lowest];
        heap[lowest] = t;

        min_heapify(lowest);
    }
}
void addHeap(int val){
    heap_size++;

    heap[heap_size]=val;
    int i=heap_size;
    while(i>1 && heap[i/2]>heap[i])swap(heap[i/2],heap[i]),i=i/2;


    return;

}
void deleteHeap(int val){
    int ind;
    for(int i=1;i<=heap_size;i++)if(heap[i]==val){ind=i;break;}
    swap(heap[ind],heap[heap_size]);
    heap_size--;
    for(int i=heap_size/2;i>0;i--)min_heapify(i);

    return;
}
int main()
{

    int i,j,k,m,n,val,total,cnt,test,sign;

    //freopen("000input.txt","r",stdin);
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&sign);
        if(sign==1){
            scanf("%d",&val);

            addHeap(val);
        }
        else if(sign == 2){
            scanf("%d",&val);

            deleteHeap(val);
        }
        else  printf("%d\n",heap[1]);

    }

    //delete();   //if pointer array
    return 0;
}
