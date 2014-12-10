#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

const int maxn = 50;

int eg[maxn][maxn];

struct pp {
    int deg,id;
    bool operator < (const pp &x) const {
        return deg < x.deg;
    }
};

pp p[maxn];

int main() {
    int T,N; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        if(kase > 1) putchar('\n');
        scanf("%d",&N);
        memset(eg,0,sizeof(eg));
        for(int i = 0;i < N;i++) {
            scanf("%d",&p[i].deg);
            p[i].id = i;
        }
        int ok = 0;
        while(1) {
            int sum = 0;
            for(int i = 0;i < N;i++) {
                sum += p[i].deg;
            }
            if(ok == -1 || sum == 0) break;
            sort(p,p + N);
            int m = p[N - 1].deg + 1;
            p[N - 1].deg = 0;
            for(int i = 2;i <= m;i++) {
                if(N - i < 0) {
                    ok = -1; break;
                } 
                p[N - i].deg--;
                if(p[N - i].deg < 0) {
                    ok = -1; break;
                }
                else eg[p[N - 1].id][p[N - i].id] = eg[p[N - i].id][p[N - 1].id] = 1;
            }
        }
        if(ok == -1) puts("NO");
        else {
            puts("YES");
            for(int i = 0;i < N;i++) {
                for(int j = 0;j < N;j++) {
                    if(j > 0) putchar(' ');
                    printf("%d",eg[i][j]);
                }
                putchar('\n');
            }
        }
    }
    return 0;
}
