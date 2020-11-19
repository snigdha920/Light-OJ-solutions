#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
#define read(x) scanf("%d", &x)
 
vector<vector<int>>adj(10100);
vector<int> mafia(10100);
int n;
lli moves=0;
vector<bool> visited(10100);
lli dfs(int vtx) {
   if(visited[vtx]) {
       return 0;
   }
   lli extra = mafia[vtx] - 1;
   visited[vtx] = true;
   for(int i=0; i < adj[vtx].size(); i++) {
       int child = adj[vtx][i];
       lli extra_temp = dfs(child);
       extra += extra_temp;
       moves += abs(extra_temp);
   }
   return extra;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++) {
        read(n);
        for(int i=0; i<=n; i++) {
            adj[i].clear();
            mafia[i] = 0;
            visited[i] = 0;
        }
        for(int i=1; i <= n; i++) {
            int city, mb, d;
            cin >> city >> mb >> d;
            mafia[city] = mb;
            for(int j=0; j<d; j++) {
                int adjc;
                cin >> adjc;
                adj[city].push_back(adjc);
                adj[adjc].push_back(city);
            }
        }
//         for(int i=1; i<=n; i++) {
//             cout << i << " -> ";
//             for(int j=0; j<adj[i].size(); j++) {
//                 cout << adj[i][j] << " ";
//             }
//             cout << endl;
//         }
//         for(int i=1; i<=n; i++) {
//             cout << mafia[i] << " ";
//         }
//         cout << endl;
        moves=0;
        dfs(1);
        printf("Case %d: %lld\n", tc, moves);
    }
}
