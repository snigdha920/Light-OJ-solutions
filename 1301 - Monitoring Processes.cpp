/*
Maximum number of intervals overlapping at a single point of time = answer
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define read(x) scanf("%d", &x)
 
bool sort_helper(const pair<lli, int> &a, const pair<lli, int> &b) {
    if(a.first < b.first) {
        return true;
    } else if(a.first > b.first) {
        return false;
    } else {
        return a.second > b. second;
    }
}
 
int main() {
    int t; read(t);
    for(int tc = 1; tc <= t; tc++) {
        int n; read(n);
        vector<pair<lli, int>>ts;
        for(int i=0; i < n; i++) {
            lli s, e;
            scanf("%lld", &s);
            scanf("%lld", &e);
            ts.push_back({s, 1});
            ts.push_back({e, -1});
        }
        sort(ts.begin(), ts.end(), sort_helper);
        // for(int i=0; i<ts.size(); i++){
        //     printf("%lld, %d\n", ts[i].first, ts[i].second);
        // }
        lli cur_sum = 0, ans = INT_MIN;
        for(int i=0; i<ts.size(); i++) {
            cur_sum += ts[i].second;
            ans = (ans > cur_sum) ? ans : cur_sum;
        }
        printf("Case %d: %lld\n", tc, ans);
    }
}
