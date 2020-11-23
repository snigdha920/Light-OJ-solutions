#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define read(x) scanf("%d", &x)
#define mod 1000007
 
int main() {
    int t; cin >> t;
    for(int tc=1; tc <= t; tc++) {
        int n; read(n);
        vector<int> a(n+1);
        a[0] = 0;
        for(int i=1; i<=n; i++) cin >> a[i];
        lli ans = -1, count=0;
        for(int i=1; i<=n; i++) {
            ans = (ans > (a[i]-a[i-1])) ? ans : (a[i]-a[i-1]);
        }
        for(int i=1; i<=n; i++) {
            if((a[i]-a[i-1]) == ans) count++;
        }
        if(count>1) ans+=1;
        printf("Case %d: %d\n", tc, ans);
    }
    return 0;
}
