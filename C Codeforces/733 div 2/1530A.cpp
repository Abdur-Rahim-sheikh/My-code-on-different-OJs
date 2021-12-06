#include<iostream>

using namespace std;

int main(){
    int k,mx,test;
    cin>>test;
    while(test--){
        cin>>k;
        mx =0;
        while(k){
            mx = max(mx,k%10);
            k/=10;
        }
        cout<<mx<<endl;
    }
    
    return 0;
}