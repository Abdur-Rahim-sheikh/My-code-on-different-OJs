#include<bits/stdc++.h>
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

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;

int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    string s;
    while(test--){
        cin>>s;
        s+='0';
        int len=s.size();
        vector<int>open(len,0),ind(len,0);


        for(k=9;k>0;k--){
            for(i=0;i<len;i++){
                char ch=k+'0';
                if(s[i]>=ch){
                    open[i]++;
                    while(s[i+1]>=ch)i++;
                    ind[i]++;
                }
            }
        }
        printf("Case #%d: ",++t);
        len--;
        for(i=0;i<len;i++){
            while(open[i])printf("("),open[i]--;
            printf("%c",s[i]);
            while(ind[i])printf(")"),ind[i]--;
        }
        printf("\n");
    }
    //free();   //if pointer array
    return 0;
}
