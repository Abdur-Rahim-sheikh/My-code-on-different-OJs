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
vector<bool> checked;
vi pos;
class trie{
    int total;
    struct box{
        int cnt;
        int alpha[26];

    }arr[1000006];
    void refresh(){
        arr[total].cnt=0;
        memset(arr[total].alpha,-1,sizeof(arr[total].alpha));
        total++;
        return;
    }
public:
    void init(){
        total=0;
        refresh();
        return;
    }
    void make_trie(string &a){
        int len=a.size(),k,cur=0;
        for(int i=0;i<len;i++){
            k=a[i]-'a';

            if(arr[cur].alpha[k]==(-1)){
                arr[cur].alpha[k]=total;
                refresh();
            }
            cur=arr[cur].alpha[k];
        }
        arr[cur].cnt++;
        return;
   }

    bool check_trie(string &a,int starts){
        int i,len=a.size(),k,cur=0;
        bool newpoint=false;
        for(i=starts;i<len;i++){
            k=a[i]-'a';
            //dbg(arr[cur].alpha[k],pos);
            if(arr[cur].alpha[k]==(-1)){
                if(!pos.empty())checked[pos.back()]=true;
                break;
            }
            cur=arr[cur].alpha[k];

            if(arr[cur].cnt>0)pos.pb(i),newpoint=true;
        }
        if(i==len)checked[pos.back()]=true;
        return newpoint==true;
    }
}tree;

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        string s;
        tree.init();
        vector<string> st(n);
        for(i=0;i<n;i++){
            cin>>st[i];
            
        }
        sort(all(st));
        for(auto u: st)tree.make_trie(u);
        cin>>s;
        checked.clear();
        pos.clear();
        checked.resize(s.size(),false);
        
        tree.check_trie(s,0);
        while(!pos.empty() and pos.back()<s.size()-1){
            //dbg("here");
            if(!tree.check_trie(s,pos.back()+1)){
                while(!pos.empty() and checked[pos.back()]){
                    checked[pos.back()]=false;
                    pos.pop_back();
                }
                
                if(!pos.empty())checked[pos.back()]=true;
            }
        }
        //dbg(pos);
        if(checked[s.size()-1]){
            int cnt=0;
            for(i=0;i<s.size();i++)if(checked[i])cnt++;
            printf("Case %d: %d\n",++t,cnt);
        }
        else{
            printf("Case %d: impossible\n",++t);
        }
    }
    //free();   //if pointer array
    return 0;
}
