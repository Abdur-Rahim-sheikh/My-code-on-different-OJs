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

int main(){

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    string s;
    cin>>test;
    while(test--){
        cin>>s;
        int len=s.size();
        int arr[len+2][len+2];
        for(i=0;i<len;i++)arr[i][i]=1,arr[i+1][i]=0;
        for(i=1;i<len;i++){
            for(j=0;i+j <len;j++){
                if(s[j]==s[i+j]){
                    arr[j][j+i]=2+arr[j+1][j+i-1];      ///diagonally left down
                }
                else{
                    arr[j][j+i]=max(arr[j][j+i-1],arr[j+1][j+i]); ///Best of left cell or down cell
                }
            }
        }
        printf("Case %d: %d\n",++t,len-arr[0][len-1]);
    }
    //free();   //if pointer array
    return 0;
}
