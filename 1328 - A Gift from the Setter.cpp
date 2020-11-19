#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
#define read(x) scanf("%d", &x)
#define mod 1000007
 
vector<lli> a(100100);
int main() {
    int t; read(t);
    for(int tc = 1; tc <= t; tc++) {
        int K, C, n;
        read(K); read(C); read(n); scanf("%lld", &a[0]);
        for(int i=1; i<n; i++) {
            lli first_term = ((K%mod)*(a[i-1]%mod))%mod;
            a[i] = (first_term%mod + C%mod)%mod;
        }
        sort(a.begin(), a.begin()+n);
//        for(int i=0; i<n; i++) cout << a[i] << " ";
//        cout << endl;
        long long ans = 0, ans1=0;
        for(int i=0; i<n; i++) {
            ans1 += (i - (n-1-i))*a[i];
//            printf("Sum at i = %d is %lld\n", i, ans1);
        }
//        cout << endl;
//        long long sum = 0;
//        int i, j;
//        for( i = 0; i < n; i++ ){
//            for( j = i + 1; j < n; j++ )
//                sum += abs( a[i] - a[j] );
//            printf("Sum at i = %d is %lld\n", i, sum);
//        }
        printf("Case %d: %lld\n", tc, ans1);
//        printf("Case %d: %lld\n", tc, sum);
    }
}
