#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
using namespace std;
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first <<gap<<','<< gap << p.second << ')';
}
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { 
    cerr << ' ' << H;
     dbg_out(T...); 
}
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')'<<':', dbg_out(__VA_ARGS__)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define on(val,pos) (val|(1<<pos))
#define off(val,pos) (val&(~(1<<pos)))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
struct stu{
    int x,y,ind;
};

bool comp(stu &p,stu &q){
    if(p.x!=q.x)return p.x<q.x;
    else return p.y<q.y;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        vector<stu> arr(n);
        for(i=0;i<n;i++){
            cin>>j>>k;
            if(j<k)swap(j,k);
            arr[i].x=j;
            arr[i].y=k;
            arr[i].ind = i+1;
        }
        sort(all(arr),comp);
        vi sol(n,-1);
        dbg(sol);
        for(i=0;i<n;i++){
            cout<<arr[i].x<<' '<<arr[i].y<<' '<<arr[i].ind<<endl;
        }
        for(i=n-2;i>=0;i--){
            for(j=n-1;j>i;j--){
                if(arr[j].x<=arr[i].x)break;
                else if(arr[j].x>arr[i].x and arr[j].y>arr[i].y){
                    sol[arr[j].ind-1]=arr[i].ind;
                    break;
                }
            }
            dbg(sol);
            if(sol[arr[j].ind-1]!=-1){
                if(arr[i].x<arr[j].y){
                    while(i>=0){
                        sol[arr[i].ind-1]=arr[j].ind;
                        i--;
                    }
                }
            }
        }
        for(auto u: sol)cout<<u<<' ';
        cout<<endl;

    }
    //free();   //if pointer array
    return 0;
}
