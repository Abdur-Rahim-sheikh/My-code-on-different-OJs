#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;
bool casesense(char a,char b){return (a|32)<(b|32);}
int main()
{

    int i,j,k,m,n,val,t=0,test;

    string a,b;
    scanf("%d%*c",&test);
    while(test--){
        getline(cin,a);
        getline(cin,b);
        i=0;j=0;
        sort(a.begin(),a.end(),casesense);
        sort(b.begin(),b.end(),casesense);
        while(a[i]==' ')i++;
        while(b[j]==' ')j++;
        val=a.length();

        while(i<val){
            if((a[i]&95)!=(b[j]&95))
                break;
            i++;j++;
        }
        if(i==val && j==b.length())printf("Case %d: Yes\n",++t);
        else printf("Case %d: No\n",++t);

    }
    //free();   //if pointer array
    return 0;
}
