#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
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
#define pll pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<int>
#define on(val,pos) (val|(1<<pos))
#define off(val,pos) (val&(~(1<<pos)))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

vector<pii> point;
stack<pii> conv;
pii ori;
bool change;
int squareLen(pii a,pii b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
bool compare(pii a,pii b){
    int t=(a.second-ori.second)*(b.first-a.first);
    int k=(b.second-a.second)*(a.first-ori.first);
    if(change and (t==k or a==ori or b==a))return false;
    else if(t==k){
        return squareLen(a,ori)<squareLen(b,ori);
    }
    else{
        return t<k;
    }
}

void graham(int n){
    stack<pii> tem;
    swap(tem,conv);
    change=true;
    conv.push(point[0]);
    conv.push(point[1]);
    conv.push(point[2]);
    int i=3;
    while(true){
        if(conv.size()<3){
            if(i==n)break;
            conv.push(point[i++]);
        }
        pii b= conv.top();conv.pop();
        pii a= conv.top();conv.pop();
        ori=conv.top();

        bool ok=compare(a,b);

        if(!ok) conv.push(b);
        else{
            conv.push(a);
            conv.push(b);

            if(i==n)break;
            conv.push(point[i++]);
        }
    }
    return;
}
double leastAngle(){
    pii a=point[0],x,b;
    x=b=conv.top();conv.pop();
    double ab,bc,ca,ans=360,tem,p;
    while(!conv.empty()){
        pii c=conv.top();conv.pop();
        ab=squareLen(a,b);
        bc=squareLen(b,c);
        ca=squareLen(c,a);
        p=(ab+bc-ca)/(2*sqrt((double)ab)*sqrt((double)bc));

        tem=(acos(p)*180.00)/PI;

        if(tem<ans)ans=tem;
        a=b;
        b=c;
    }
    ab=squareLen(a,b);
    bc=squareLen(b,x);
    ca=squareLen(x,a);
    p=(ab+bc-ca)/(2*sqrt((double)ab)*sqrt((double)bc));
    tem=(acos(p)*180.00)/PI;
    if(tem<ans)ans=tem;

    return ans;
}

bool solves(pair<pii,pii> a, pii b){
    return (b.x-a.x.x)*(a.x.y-a.y.y)-(b.y-a.x.y)*(a.x.x-a.y.x)==0;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        point.clear();
        point.resize(n);
        
        cin>>point[0].x>>point[0].y;
        for(i=1;i<n;i++){
            cin>>j>>k;
            point[i]={j,k};
            if(j<point[0].x or (j==point[0].x and k<point[0].y)){
                swap(point[0],point[i]);
            }
        }
        if(n<3){
            printf("Case %d: %d\n",++t,n);
            continue;
        }
        ori = point[0];
        change=false;
        sort(point.begin()+1,point.end(),compare);
        graham(n);
        vector<pii> final;
        while(!conv.empty()){
            final.pb(conv.top());
            conv.pop();
        }
        int cnt,maxi=1;
        for(i=0;i<final.size();i++){
            for(j=i+1;j<final.size();j++){
                
                pair<pii,pii> tem = {final[i],final[j]};
                
                for(k=0,cnt=0;k<n;k++){
                    if(solves(tem,point[k]))cnt++;
                }
                maxi = max(maxi,cnt);
            }
        }
        printf("Case %d: %d\n",++t,maxi);
    }
    //free();   //if pointer array
    return 0;
}
