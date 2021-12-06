#include<iostream>
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
pair<int,int> cord[20],setA[10],setB[10];
bool checked[20];
double min_dist;
double dist(int i){
    int it=40;
    double a=setA[i].first-setB[i].first;
    double b=setA[i].second-setB[i].second;
    double val=a*a+b*b;
    double low=0,high=val,mid;
    while(it--){
        mid=(low+high)/2;
        if(mid*mid>val)high=mid;
        else low=mid;
    }
    return mid;
}
double get_min(int i,int n){
    //cout<<"in__here"<<endl;
    if(i==n){
        double sum=0;
        for(int i=0;i<n;i++){
            
            sum+=dist(i);
        }
        return sum;
    }
    for(int j=0;j<2*n;j++){
        if(checked[j]==true)continue;
        checked[j]=true;
        setA[i]=cord[j];
        for(int k=j+1;k<2*n;k++){
            if(checked[k]==true)continue;
            checked[k]=true;
            setB[i]=cord[k];
             double sum=get_min(i+1,n);
             if(sum<min_dist)min_dist=sum;
            checked[k]=false;
        }
        checked[j]=false;
    }
    return min_dist;
}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,x,y;
    char name[100];
    //freopen("000input.txt","r",stdin);
    while(scanf("%d",&n)==1 && n!=0){
        for(i=0;i<2*n;i++) scanf(" %s %d %d",name,&cord[i].first,&cord[i].second);
        min_dist=INF;
        printf("Case %d: %0.2lf\n",++t,get_min(0,n));
    }
    //free();   //if pointer array
    return 0;
}

