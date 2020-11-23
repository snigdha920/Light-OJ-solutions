#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define read(x) scanf("%d", &x)
#define mod 1000007
 
vector<pair<lli, lli>> a;
int k, n, s;
lli d;
bool check(lli cur) {
    vector<pair<lli, lli>>intervals;
    for(int i=0; i<n; i++) {
        lli h = a[i].second-cur;
        if(h > d) return false;
        lli x = sqrt(1.0*d*d - 1.0*h*h);
        intervals.push_back({a[i].first+x, a[i].first-x});
    }
    lli count=1;
    sort(intervals.begin(), intervals.end());
    lli last = intervals[0].first;
    for(int i=1; i<intervals.size(); i++) {
        if(intervals[i].second > last) {
            count++;
            last = intervals[i].first;
        }
    }
    // cout << "parts: " << count << endl;
    return count <= s;
}
int main() {
    int t; cin >> t;
    for(int tc=1; tc <= t; tc++) {
        cin >> k >> n >> s >> d;
        a.resize(n);
        lli maxy = k-1;
        for(int i=0; i<n; i++) {
            cin >> a[i].first >> a[i].second;
            maxy = (maxy > a[i].second) ? maxy : a[i].second;
        }
        if(!check(k)) {
            printf("Case %d: impossible\n", tc);
            continue;
        }
        lli right=k, left=k-d-10;
        while(left+1 < right) {
            lli mid=(left+right)/2;
            if(check(mid)) {
                right=mid;
            } else {
                left=mid;
            }
        }
        printf("Case %d: %lld\n", tc, k-right);
    }
    return 0;
}
