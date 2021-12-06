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
    string a,b;
    cin>>test;
    while(test--){
        cin>>a;
        b=a;
        reverse(a.begin(),a.end());
        a+=b;
        int arr[a.size()+5];
        arr[0]=0;
        //fill(arr,arr+a.size(),0);
        for(i=1,j=0;i<a.size();i++){
            if(i*2==a.size())j=0;
            if(a[i]==a[j])arr[i]=++j;
            else{
                //cout<<j<<' '<<a[i]<<' '<<a[j]<<endl;
                while(j>0 && a[i]!=a[j])j=arr[j-1];
                if(a[i]==a[j])arr[i]=++j;
                else arr[i]=0;
            }

        }

        printf("Case %d: %d\n",++t,(a.size()-j));

    }
    //free();   //if pointer array
    return 0;
}
