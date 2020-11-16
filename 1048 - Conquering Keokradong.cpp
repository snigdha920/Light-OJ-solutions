#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
 
int n, k;
vector<int> s;
vector<int> ans;
bool good(int x) {
    ans.clear();
    int cur = 0;
    bool flag = 1;
    for(int i = 0; i <= n; i++) {
        if(s[i] > x) {
            flag = 0;
            break;
        }
        cur += s[i];
        if(cur > x) {
            cur -= s[i];
            ans.push_back(cur);
            cur = s[i];
        }
    }
    ans.push_back(cur);
    if (flag == 0) return 0;
    else return ans.size() <= k+1;
}
int main() {
    int t;
    scanf("%d", &t);
    for (int ti = 1; ti <= t; ti++) {
        scanf("%d", &n);
        scanf("%d", &k);
        s.resize(n+1);
        int l = INT_MIN, r = 0;
        for( int i = 0; i <= n; i++) {
            scanf("%d", &s[i]);
            r += s[i];
            if(s[i] > l) l = s[i];
        }
        // int cnt = 0;
       l -= 10;
        while(l+1 < r) {
            int mid = (l + r)/2;
            // cnt++;
            // good of mid is true if cost of walking is less than mid
            if (good(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("Case %d: %d\n", ti, r);
        good(r);
        // cout << "good " << good(r) << endl;
        // cout << cnt << endl;
        // for(int i = 0; i < ans.size(); i++) {
        //     printf("%d\n", ans[i]);
        // }
        n++; k++;
        int cnt=k,cur=0;
        for(int i=0;i<n;i++)
           {
                   cur+=s[i];
              if(cur>r || n-i+1==cnt)
              {
                     cnt--;
                     cur-=s[i];
                     printf("%d\n",cur);
                     cur=s[i];
              }
 
           }
           printf("%d\n",cur);
    }
    return 0;
}
