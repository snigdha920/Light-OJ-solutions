#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define read(x) scanf("%d", &x)
#define mod 1000007
 
int main() {
    int t; cin >> t;
    for(int tc=1; tc <= t; tc++) {
        int n; read(n);
        string s; cin >> s;
        int ans=0;
        bool used[n];
        memset(used, 0, sizeof(used));
        for(int i=0; i<n; i++) {
            if(s[i]=='.' && used[i]==0) {
                if(i<n && used[i+1]==0) {
                    used[i] = 1;
                    if(i<n-1) used[i+1] = 1;
                    if(i<n-2) used[i+2] = 1;
                    ans++;
                } else {
                    if(i>0) used[i-1]=1;
                    if(i<n-1) used[i+1]=1;
                    ans++;
                    used[i]=1;
                }
            }
        }
        printf("Case %d: %d\n", tc, ans);
    }
    return 0;
}
/*
#.# | ... | ..# | #.. | .#. | ### | ##. | .##
*/
