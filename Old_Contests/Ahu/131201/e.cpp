#include <cstdio>

using namespace std;

int h[1001],N;

int main() {
	int ans = 0,now = 0;
	scanf("%d",&N);
	for(int i = 1;i <= N;i++) scanf("%d",&h[i]);
	for(int i = 1;i <= N;i++) {
		now = 1;
		for(int j = i - 1;j > 0 && h[j] <= h[j + 1];j--) now++;
		for(int j = i + 1;j <= N && h[j] <= h[j - 1];j++) now++;
		if(now > ans) ans = now;
	}
	printf("%d\n",ans);
	return 0;
}
