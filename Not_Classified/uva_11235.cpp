#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

#define max(a,b) (((a)>(b))?(a):(b))


const int maxn = 100005;
int value[maxn],count[maxn],num[maxn],left[maxn],right[maxn],A[maxn];
int N,M,d[maxn][18];

int main() {
	while(scanf("%d",&N),N) {
		scanf("%d",&M);
		for(int i = 1;i <= N;i++) {
			scanf("%d",&A[i]);
		}
		//进行游程编码，nowseg表示现在已经编码到第几段
		int nowseg = 0,nowcnt = 0;
		A[N + 1] = INF;
		for(int i = 1;i <= N + 1;i++) {
			//出现了一段的结束
			if(i > 1 && A[i] != A[i - 1]) {
				value[nowseg] = A[i - 1];
				count[nowseg] = nowcnt;
				for(int j = i - nowcnt;j < i;j++) {
					left[j] = i - nowcnt;
					right[j] = i - 1;
				}
				nowseg++; nowcnt = 0;
			}
			num[i] = nowseg;
			nowcnt++;
		}
		//初始化ST数组
		//RMQ用于查询第i段到第j段中出现次数最多的段
		for(int i = 0;i < nowseg;i++) d[i][0] = count[i];
		for(int j = 1; (1 << j) <= nowseg;j++) {
			for(int i = 0;i + (1 << j) - 1 < nowseg;i++) {
				d[i][j] = max(d[i][j - 1],d[i + (1 << (j - 1))][j - 1]);
			}
		}
		//开始查询
		while(M--) {
			int ql,qr; scanf("%d%d",&ql,&qr);
			//如果ql和qr是在同一段中的
			if(num[ql] == num[qr]) {
				printf("%d\n",qr - ql + 1);
			} else {
				//如果不是同一段中的，则有三种可能
				int ans = right[ql] - ql + 1;	//来自左边界
				ans = max(ans,qr - left[qr] + 1); //来自右边界
				//来自中间，RMQ查询right[ql] + 1到left[qr] - 1
				ql = num[ql] + 1; qr = num[qr] - 1;
				if(ql <= qr) {
					int k = 0;
					while((1 << (k + 1)) <= qr - ql + 1) k++;
					int ret = max(d[ql][k],d[qr - (1 << k) + 1][k]);
					ans = max(ans,ret);
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}


