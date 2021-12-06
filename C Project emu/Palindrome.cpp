#include<iostream>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    int arr[n+5];
    for(i=0;i<n;i++)cin>>arr[i];

    for(i=0;i<n/2;i++){   ///As we know a string will be palindrome if(i=0,1..n-1)
        if(arr[i]!=arr[n-i-1])break; ///s[i] and s[n-i-1] are same alphabet.
    }

    if(i<(n/2))cout<<"Not palindrome."<<endl;
    else cout<<"Palindrome!"<<endl;
}
