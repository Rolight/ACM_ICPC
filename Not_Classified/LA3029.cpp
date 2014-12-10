#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;
const int maxn = 1005;
int T,M,N,mat[maxn][maxn],right[maxn][maxn],left[maxn][maxn],up[maxn][maxn];

int main() {
	scanf("%d",&T);
	while(T--) {
		int ans = 0;
		scanf("%d%d",&N,&M);
		char ch;
		for(int i = 1;i <= N;i++) {
			for(int j = 1;j <= M;j++) {
				scanf(" %c",&ch);
				mat[i][j] = (ch == 'R' ? 0 : 1);
			}
		}
		memset(right,0,sizeof(right));
		memset(left,0,sizeof(left));
		memset(up,0,sizeof(up));
		for(int i = 1;i <= M;i++) {
			left[0][i] = right[0][i] = maxn;
		}
		for(int i = 1;i <= N;i++) {
			int lo = 0,ro = M + 1;
			for(int j = 1;j <= M;j++) {
				if(mat[i][j]) {
					if(mat[i - 1][j] == 0) {
						up[i][j] = 0;
					} else {
						up[i][j] = up[i - 1][j] + 1;
					}

					if(mat[i][j - 1] == 0) {
						left[i][j] = 0;
					} else if(mat[i - 1][j] == 0) {
						left[i][j] = j - lo - 1;
					} else {
						left[i][j] = min(left[i - 1][j],j - lo - 1);
					}
				} else {
					lo = j;
				}
			}

			for(int j = M;j >= 1;j--) {
				if(mat[i][j]) {
					if(mat[i][j + 1] == 0) {
						right[i][j] = 0;
					} else if(mat[i - 1][j] == 0) {
						right[i][j] = ro - j - 1;
					} else {
						right[i][j] = min(right[i - 1][j],ro - j - 1);
					}
					ans = max(ans,(up[i][j] + 1) * (left[i][j] + right[i][j] + 1) * 3);
					//printf("ans = %d,%d,%d,%d,%d,%d\n",ans,i,j,left[i][j],right[i][j],up[i][j]);
				} else {
					ro = j;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
