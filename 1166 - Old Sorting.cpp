#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int n;
vector<int>a;
int main() {
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t; ti++) {
        scanf("%d", &n);
        a.resize(n+1);
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        int res = 0;
        for(int i=1; i <= n; i++) {
            if(a[i] != i) {
                for(int j = i+1; j<=n; j++) {
                    if(a[j] == i) {
                        swap(a[j], a[i]);
                        res++;
                        break;
                    }
                }
            }
        }
        printf("Case %d: %d\n", ti, res);
    }
    return 0;
}








