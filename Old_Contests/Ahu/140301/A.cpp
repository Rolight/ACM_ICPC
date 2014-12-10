#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 502;

struct node {
	int deg,val;
};

node g[maxn][maxn];
int n,m,k;

void delmin() {
    while(k) {
        queue<int> qx,qy;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(g[i][j].val == 1 && g[i][j].deg <= 1) {
                    qx.push(i); qy.push(j);
                }
            }
        }
        while(!qx.empty() && k) {
            int i = qx.front(),j = qy.front();
            k--;
            g[i][j].val = 2;
            g[i - 1][j].deg--; g[i + 1][j].deg--; g[i][j - 1].deg--; g[i][j + 1].deg--;
            qx.pop(); qy.pop();
        }
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
	char tmp;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			scanf(" %c",&tmp);
			if(tmp == '#') g[i][j].val = 0;
			else g[i][j].val = 1;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			g[i][j].deg = g[i - 1][j].val + g[i + 1][j].val + g[i][j - 1].val + g[i][j + 1].val;
		}
	}
	delmin();
	for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(g[i][j].val == 0) putchar('#');
            else if(g[i][j].val == 1) putchar('.');
            else putchar('X');
        }
        putchar('\n');
	}
	return 0;
}
