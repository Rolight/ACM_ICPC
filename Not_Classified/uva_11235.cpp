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
		//�����γ̱��룬nowseg��ʾ�����Ѿ����뵽�ڼ���
		int nowseg = 0,nowcnt = 0;
		A[N + 1] = INF;
		for(int i = 1;i <= N + 1;i++) {
			//������һ�εĽ���
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
		//��ʼ��ST����
		//RMQ���ڲ�ѯ��i�ε���j���г��ִ������Ķ�
		for(int i = 0;i < nowseg;i++) d[i][0] = count[i];
		for(int j = 1; (1 << j) <= nowseg;j++) {
			for(int i = 0;i + (1 << j) - 1 < nowseg;i++) {
				d[i][j] = max(d[i][j - 1],d[i + (1 << (j - 1))][j - 1]);
			}
		}
		//��ʼ��ѯ
		while(M--) {
			int ql,qr; scanf("%d%d",&ql,&qr);
			//���ql��qr����ͬһ���е�
			if(num[ql] == num[qr]) {
				printf("%d\n",qr - ql + 1);
			} else {
				//�������ͬһ���еģ��������ֿ���
				int ans = right[ql] - ql + 1;	//������߽�
				ans = max(ans,qr - left[qr] + 1); //�����ұ߽�
				//�����м䣬RMQ��ѯright[ql] + 1��left[qr] - 1
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


