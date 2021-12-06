#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test;
    string a;
    char l[2000],r[2000];
    cin>>n>>a;
    int cp_n=n;
    i=0,j=0,k=0;
    while(i+j<cp_n){
        if(n&1){
            r[i]=a[k];
            i++;
            k++;
            n--;
        }
        if(i+j==cp_n)break;
        l[j]=a[k];
        j++;
        k++;
        n--;
    }
    l[j]='\0';
    r[i]='\0';
    while(j>0)printf("%c",l[--j]);
    while(j<i)printf("%c",r[j++]);
    printf("\n");
    //free();   //if pointer array
    return 0;
}
