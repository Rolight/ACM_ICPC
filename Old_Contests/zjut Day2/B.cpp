#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 751;
int sum[maxn],num[maxn][maxn],pos[maxn];

using namespace std;

int main() {
	int k;
	while(~scanf("%d",&k)) {
		int sum = 0;
		memset(pos,0,sizeof(pos));
		for(int i = 0;i < k;i++) {
			for(int j = 0;j < k;j++) scanf("%d",&num[i][j]);
			sort(num[i],num[i] + k);
			sum += num[i][0];
		}
		printf("%d ",sum);
		for(int i = 1;i < k;i++) {
			int min = 2100000000,minj;
			for(int j = 0;j < k;j++) if(pos[j] < k - 1){
				int d = num[j][pos[j] + 1] - num[j][pos[j]];
				if(d < min) {
					min = d; minj = j;
				}
			}
			printf("%d\n",minj);
			sum += min; pos[minj]++;
			if(i != k - 1) putchar(' ');
			else putchar('\n');
		}
	}
	return 0;
}
