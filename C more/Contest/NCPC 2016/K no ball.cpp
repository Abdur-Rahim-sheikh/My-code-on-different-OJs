#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
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
    while(test--){
        string s;
        string ans="Thik Ball";
        for(i=0;i<5;i++){
            cin>>s;
            for(j=0;s[j]!='|';j++){
                if(s[j]=='<')ans="No Ball";
            }
            for(j++;j<5;j++){
                if(s[j]=='>')ans="No Ball";
            }

        }
        printf("Case %d: ",++t);
        cout<<ans<<endl;
    }
    //free();   //if pointer array
    return 0;
}
