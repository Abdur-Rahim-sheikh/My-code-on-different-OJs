#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
#define mod 1000000007
#define ll long long
#define endl '\n'
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
//replace less<int> to less_equal<int> to take duplicate values
double sum;
int tst;
void solve(double a,double b,double c,double val,double predict=1,double cnt=0){
    if (c==0.0){
        sum+=predict*cnt;
        //dbg(tst,sum,predict);
        return;
    }
    double will_get = (a>0.0)+(b>0.0);//(c>0.0)-1==0
    double x,p,q,r;
    if(a!=0.0){
        if(a-val>0.0000001)  x = val/will_get,p=a-val;
        else x=a/will_get,p = 0;
        q = b==0.0?0:b+x;
        r = c+x;
        //dbg(predict,a);
        solve(p,q,r,val,predict*a,cnt+1);
    }

    if(b!=0.0){
        if(b-val>0.0000001)  x = val/will_get,q=b-val;
        else x=b/will_get,q = 0;
        p = a==0.0?0:a+x;
        r = c+x;
        //dbg(predict,b);
        solve(p,q,r,val,predict*b,cnt+1);
    }
    if(c!=0.0){
        //dbg(predict,c);
        solve(0,0,0,0,predict*c,cnt+1);
    }
}
int main(){
    double n,m,val,k;
    int i,j,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>m>>k>>val;
        tst = test;
        sum=0;
        solve(n,m,k,val);
        printf("%.12lf\n",sum);
    }
    //free();   //if pointer array
    return 0;
}
