#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define Hare printf("here")
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)(val&(1<<pos))
using namespace std;
struct add{
        int roll,mark;
        string name;
};

bool comp(add a,add b){
    if(a.mark!=b.mark)return a.mark>b.mark;
    else return a.roll<b.roll;
}
int main(){

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>n;
    add arr[n+5];

    for(i=0;i<n;i++) cin>>arr[i].roll>>arr[i].name>>arr[i].mark;
    sort(arr,arr+n,comp);
    cout<<"Roll | Name       | Marks"<<endl;
    cout<<"-------------------------"<<endl;
    for(i=0;i<n;i++){
        printf("%4d | ",arr[i].roll);
        cout<<arr[i].name;
        for(j=arr[i].name.size()-1;j<10;j++)printf(" ");
        printf("| ");
        printf("%d\n",arr[i].mark);
    }
    //free();   //if pointer array
    return 0;
}
