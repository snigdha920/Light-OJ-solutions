#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define read(x) scanf("%d", &x)
#define mod 1000007
 
int main() {
    int t; cin >> t;
    for(int tc=1; tc <= t; tc++) {
        string number; cin >> number;
        int n=number.length(); bool all9 = 1;
        vector<int>num(n), ans(n);
        for(int i=0; i<n; i++) {
            num[i] = number[i]-'0';
            if(num[i] != 9) all9 = false;
            if(i < (n+1)/2) ans[n-1-i] = ans[i] = num[i];
        }
        if(n == 1) {
            if(num[0] == 9) printf("Case %d: 11\n", tc);
            else printf("Case %d: %d\n", tc, num[0]+1);
            continue;
        }
        if (all9) {
            printf("Case %d: 1", tc);
            for(int i=1; i<n; i++) cout << 0 ;
            cout << 1 ;
            cout << endl;
            continue;
        }
        bool big = 0;
        for(int i=0; i<n; i++) {
            if(ans[i] > num[i]) {
                big = 1;
                break;
            }
            if(ans[i] < num[i]) {
                break;
            }
        }
        if(big) {
            printf("Case %d: ", tc);
            for(int i=0; i <n; i++) cout << ans[i];
            cout << endl;
        } else {
            int carry=1;
            for(int i=(n-1)/2; i>=0; i--) {
                int temp=ans[i];
                ans[i]=(temp+carry)%10;
                carry=(temp+carry)/10;
                if(carry == 0) break;
            }
            for(int i=0; i<(n+1)/2; i++) {
                ans[n-1-i] = ans[i];
            }
            printf("Case %d: ", tc);
            for(int i=0; i <n; i++) cout << ans[i];
            cout << endl;
        }
    }
    return 0;
}
