#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int i, j, n, k, a[50000], tmp, diff, sum, maxi, mini;
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort (a, a+n);
    j = 0;
    sum = 0;
    for (i = n - 1; i > 0; i--) {
        diff = a[i] - a[i-1];
        sum += ((j+1)*diff);
        cout << diff <<" " << sum << endl;
        if(sum > k) {
            maxi = a[i];
            break;
        }
        j++;
    }
    sum = 0;
    for (i = 0; i < n-1; i++) {
        diff = abs(a[i]- a[i-1]);
        sum += (i*diff);
        if(sum > k) {
            mini = a[i-1];
            break;
        }
    }
    cout << maxi << " " << mini << endl;

    return 0;

}
}
