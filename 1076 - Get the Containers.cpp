#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
 
// low = max(arr[..])
// high = sum(arr[..])
// good(x)
// checks if maximum capacity x can fill m containers or not
// if we can fill m containers in maximum capacity x then right = x & check for [low, right]
// if we cant fill m containers in maximum capcity x then low = x & check for [low, right]
 
vector<lli> v;
int n, m;
lli l, r;
 
bool good(lli x) {
    lli cur = 0;
    int count = 0;
    for(int i=0; i<n; i++) {
        cur += v[i];
        if(cur > x) {
            count++;
            cur = v[i];
        }
    }
    count++;
    return count <= m;
}
 
int main() {
    int t;
    scanf("%d", &t);
    for (int ti=1; ti <= t; ti++) {
        scanf("%d", &n);
        scanf("%d", &m);
        v.resize(n);
        l = INT_MIN;
        r = 0;
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
            if(v[i] > l) l = v[i];
            r += v[i];
        }
        while(l < r) {
            lli mid = (l + r)/2;
            if(good(mid)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        printf("Case %d: %lld\n", ti, r);
    }
    return 0;
}
