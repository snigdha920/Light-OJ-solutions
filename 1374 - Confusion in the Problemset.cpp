#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define read(x) scanf("%d", &x)
#define mod 1000007
 
int main() {
    int t; cin >> t;
    for(int tc=1; tc <= t; tc++) {
        int n; scanf("%d", &n);
        bool put[n];
        memset(put, 0, sizeof(put));
        vector<int> a(n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        if(n == 1) {
            if(a[0] == 0) {
                printf("Case %d: yes\n", tc);
            } else {
                printf("Case %d: no\n", tc);
            }
            continue;
        }
        bool flag=1;
        for(int i=0; i<n; i++) {
            if(a[i] > n && n-1-a[i] < 0) {
                flag = 0;
                break;
            }
            if(a[i] < n && put[a[i]]==0) {
                put[a[i]] = 1;
            } else if(n-1-a[i] >= 0 && put[n-1-a[i]]==0) {
                put[n-1-a[i]] = 1;
            } else {
                flag = 0;
                break;
            }
        }
        if(flag) {
            printf("Case %d: yes\n", tc);
        } else {
            printf("Case %d: no\n", tc);
        }
    }
    return 0;
}
