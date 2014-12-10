#include <cstdio>
using namespace std;
const int maxn = 300;
const int sz = 9;
int k[maxn][sz][maxn][sz],val[maxn][maxn],n,m,q;

#define p2(x) (1<<(x))
#define max2(x,y) (((x)<(y))?(y):(x))
#define max(a,b,c,d) (max2(max2(a,b),max2(c,d)))

void init_RMQ() {
    for(int px = 0;(1 << px) <= n;px++) {
        for(int py = 0;(1 << py) <= m;py++) {
            for(int i = 0;i+p2(px) < n+1;i++) {
                for(int j = 0;j+p2(py) < m+1;j++) {
                	int &now = k[i][px][j][py];
                	if(px == 0 && py == 0) {
                		now = val[i][j];
                	} else if(px == 0 && py != 0) {
                		now = max2(k[i][px][j][py-1],k[i][px][j+p2(py-1)][py-1]);
                	} else if(px != 0 && py == 0) {
                		now = max2(k[i][px-1][j][py],k[i+p2(px-1)][px-1][j][py]);
                	} else {
	                    now = max(
	                        k[i][px-1][j][py-1],
	                        k[i+p2(px-1)][px-1][j][py-1],
	                        k[i][px-1][j+p2(py-1)][py-1],
	                        k[i+p2(px-1)][px-1][j+p2(py-1)][py-1]
	                        );
                    }
                }
            }
        }
    }
}

int query(int qx1,int qy1,int qx2,int qy2) {
    int kx = 0,ky = 0;
    while(p2(kx+1) <= qx2 - qx1 + 1) kx++;
    while(p2(ky+1) <= qy2 - qy1 + 1) ky++;
    return max(
        k[qx1][kx][qy1][ky],
        k[qx2-p2(kx)+1][kx][qy1][ky],
        k[qx1][kx][qy2-p2(ky)+1][ky],
        k[qx2-p2(kx)+1][kx][qy2-p2(ky)+1][ky]
            );
}

int main() {
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                scanf("%d",&val[i][j]);
            }
        }
        init_RMQ();
        scanf("%d",&q);
        while(q--) {
            int qx1,qy1,qx2,qy2;
            scanf("%d%d%d%d",&qx1,&qy1,&qx2,&qy2);
            qx1--; qy1--; qx2--; qy2--;
            int ret = query(qx1,qy1,qx2,qy2);
            printf("%d ",ret);
            if(ret == val[qx1][qy1] || ret == val[qx1][qy2] ||
                ret == val[qx2][qy1] || ret == val[qx2][qy2]) 
                puts("yes");
            else puts("no");
        }
    }
    return 0;    
}
