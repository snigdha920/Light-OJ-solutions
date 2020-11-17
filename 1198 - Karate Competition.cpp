#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
 
int n;
vector<int>a;
vector<int>b;
int main() {
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t; ti++) {
        scanf("%d", &n);
        a.resize(n);
        b.resize(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &b[i]);
        }
        int score=0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        bool useda[n], usedb[n];
        memset(useda, 0, sizeof(useda));
        memset(usedb, 0, sizeof(usedb));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(usedb[j] == 1) continue;
                if(a[i] > b[j]) {
                    score+=2;
                    useda[i] = 1;
                    usedb[j] = 1;
                    break;
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(useda[i] == 1) continue;
            for(int j=0; j<n; j++) {
                if(usedb[j] == 1) continue;
                if(a[i] > b[j]) {
                    score += 2;
                    useda[i] = 1;
                    usedb[j] = 1;
                    break;
                }
                if(a[i] == b[j]) {
                    score += 1;
                    useda[i] = 1;
                    usedb[j] = 1;
                    break;
                }
            }
        }
        printf("Case %d: %d\n", ti, score);
    }
    return 0;
}
 
