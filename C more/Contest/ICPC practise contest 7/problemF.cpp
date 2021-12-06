#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
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

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    int point[2]={0,0},win[2]={0,0};
    string s;
    cin>>s;
    int server=0;
    for(i=0;i+1<s.size();i++){
        if(s[i]=='S')point[server]++;
        else if(s[i]=='R'){
            server^=1;
            point[server]++;
        }
        else{
            string tem;
            tem = to_string(win[0])+" ("+to_string(point[0]);
            if(server==0)tem+="*";
            tem+= ") - "+to_string(win[1])+" ("+to_string(point[1]);
            if(server==1)tem+="*";
            tem+= ")";
            cout<<tem<<endl;
        }
        int mx=max(point[0],point[1]);
        if((mx>=5 and abs(point[0]-point[1])>=2)or mx==10){
            if(point[server]!=mx)server^=1;
            win[server]++;
            point[0]=point[1]=0;
        }
    }
    if(s[i]=='Q'){
        string tem;
        tem = to_string(win[0]);
        if(win[0]>win[1])tem+=" (winner)";
        tem+= " - "+to_string(win[1]);
        if(win[1]>win[0])tem+=" (winner)";
        cout<<tem<<endl;
    }
    //free();   //if pointer array
    return 0;
}
