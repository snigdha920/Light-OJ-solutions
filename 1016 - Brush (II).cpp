#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
 
int main() {
    int t;
    scanf("%d", &t);
    for (int ti = 1; ti <= t; ti++) {
        int n, w;
        scanf("%d", &n);
        scanf("%d", &w);
        lli count = 0;
        vector < pair < int, int > > p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i].second >> p[i].first;
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < n; i++) {
            int yi = p[i].first;
            count++;
            while(i < n && p[i].first <= yi + w) {
                i++;
            }
            if(i < n) i--;
        }
        cout << "Case " << ti << ": " << count << endl;
        // cout << "Case " << ti << ": " << n << endl;
        // cout << "Case " << ti << ": " << w << endl;
    }
    return 0;
}
