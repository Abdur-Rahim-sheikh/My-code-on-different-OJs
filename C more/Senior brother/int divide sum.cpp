#include <bits/stdc++.h>
using namespace std;
long long int sum(long long int n)
{
    long long int root = sqrt(n);
    long long int ans = 0;

    for (int i = 1; i <= root; i++)
        ans += n / i;

    ans = 2 * ans - (root * root);
    return ans;
}

// driver code
int main()
{
    long long n,test,t=0;
    cin>>test;
    while(test--){
          scanf("%lld",&n);
          printf("Case %lld: %lld\n",++t,sum(n));
           // cout << sum(n)<<endl;
    }

    return 0;
}
