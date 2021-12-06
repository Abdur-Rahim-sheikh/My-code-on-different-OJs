#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    string a,b,dash;
    for(i=0;i<80;i++)dash+='-';
    while(getline(cin,a)){
        if(a.size()>0){
            b+=a;
            b+=' ';
        }
    }
    stringstream ss(b);
    a=b="";
    while(ss>>a){
        if(a=="<br>")cout<<b<<endl,b="";
        else if(a=="<hr>"){
            if(b.size())cout<<b<<endl,b="";
            cout<<dash<<endl;
        }
        else{
            if(b.size()+a.size()>=80)cout<<b<<endl,b=a;
            else if(b.size()){
                b+=' ';
                b+=a;
            }
            else b=a;
        }
    }
    if(b.size())cout<<b<<endl;
    //free();   //if pointer array
    return 0;
}
