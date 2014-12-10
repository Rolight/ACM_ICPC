#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 10;
char mp[maxn][maxn];

bool ok(int x,int y) {
    bool a1 = true,a2 = true,a3 = true,a4 = true;
    char c = mp[x][y];
    for(int i = 1;i <= 4;i++) if(mp[i][y] != c && mp[i][y] != 'T') a1 = false;
    for(int i = 1;i <= 4;i++) if(mp[x][i] != c && mp[x][i] != 'T') a2 = false;
    if(!(x == y || x == 4 - y + 1)) return a1 || a2;
    for(int i = 1;i <= 4;i++) if(mp[i][i] != c && mp[i][i] != 'T') a3 = false;
    for(int i = 1;i <= 4;i++) if(mp[i][4 - i + 1] != c && mp[i][4 - i + 1] != 'T') a4 = false;
    return a1 || a2 || a3 || a4;
}


int main() {
    int kase = 1;
    int T; scanf("%d",&T);
    while(T--) {
        bool found = false;
        int pcnt = 0;
        for(int i = 1;i <= 4;i++) {
            for(int j = 1;j <= 4;j++) {
                scanf(" %c",&mp[i][j]);
                if(mp[i][j] == '.') pcnt++;
            }
        }
        printf("Case #%d: ",kase++);
        for(int i = 1;i <= 4;i++) {
            for(int j = 1;j <= 4;j++) if(mp[i][j] == 'X' || mp[i][j] == 'O') {
                if(ok(i,j)) {
                    found = true;
                    if(mp[i][j] == 'X') {
                        puts("X won");
                    }
                    else puts("O won");
                    break;
                }
            }
            if(found) break;
        }
        if(!found) {
            if(pcnt == 0) puts("Draw");
            else puts("Game has not completed");
        }
    }
}
