#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
//first four adjacent,second four corner
//ll row[8]={0,-1,0,1,1,-1,-1,1};
//ll col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
pii point[100005];
stack<pii> conv;
pii ori;
bool change;
ll squareLen(pii a,pii b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
bool compare(pii a,pii b){
    ll t=(a.second-ori.second)*(b.first-a.first);
    ll k=(b.second-a.second)*(a.first-ori.first);
    if(change and (t==k or a==ori or b==a))return false;
    else if(t==k){
        return squareLen(a,ori)<squareLen(b,ori);
    }
    else{
        return t<k;
    }
}

void graham(ll n){
    stack<pii> tem;
    swap(tem,conv);
    change=true;
    conv.push(point[0]);
    conv.push(point[1]);
    conv.push(point[2]);
    ll i=3;
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
int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;

    while(test--){
        cin>>n>>point[0].first>>point[0].second;

        for(i=1;i<n;i++){
            scanf("%lld %lld",&j,&k);
            point[i]={j,k};

            if(k<point[0].second ||(k==point[0].second && j<point[0].first)){
                swap(point[0],point[i]);
            }
        }
        if(n<3){
            printf("Case %lld: 0\n",++t);
            continue;
        }

        ori=point[0];
        change=false;
        sort(point+1,point+n,compare);
        graham(n);
        //cout<<conv.size()<<endl;
        if(conv.size()<3)printf("Case %lld: 0\n",++t);
        else printf("Case %lld: %0.8lf\n",++t,leastAngle());
    }
    //free();   //if pointer array
    return 0;
}
