#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define p1(n) printf("showing %d\n",n)
#define p2(m,n) printf("showing %d %d\n",m,n)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
vector<int>arr(100005);
void count(int &sq,int &rec,char ch, int n){

    if(ch=='-'){
        if(arr[n]%4==0)sq--;
        if(arr[n]%2==0)rec--;
        arr[n]--;
    }
    else{
        arr[n]++;
        if(arr[n]%4==0)sq++;
        if(arr[n]%2==0)rec++;
    }
}
int main(){
    int i,j,k,n,m,val,t=0,q;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    char ch;
    int sq=0,rec=0;
    for(i=0;i<n;i++){
        cin>>val;
        count(sq,rec,'+',val);
    }
    cin>>q;
    for(i=0;i<q;i++){
        cin>>ch>>val;
        count(sq,rec,ch,val);
        if(sq>0 and rec>=4)printf("Yes\n");
        else printf("No\n");
    }
    //free();   //if pointer array
    return 0;
}
