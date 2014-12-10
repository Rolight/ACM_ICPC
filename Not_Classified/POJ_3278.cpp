#include <cstdio>
#include <cstring>
#include <queue>

#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

const int maxn = 100002;
int t[maxn * 3];

int main() {
	int n,k;
	while(~scanf("%d%d",&n,&k)) {
		if(k < n) {
			printf("%d\n",n - k);
			continue;
		}
		queue<int> q;
		memset(t,111,sizeof(t));
		q.push(n);
		t[0] = -1; t[n] = 0;
		while(!q.empty()) {
			int now = q.front(),nowt = t[now];
			int next[3] = {now - 1,now + 1,now * 2};
			for(int i = 0;i < 3;i++) if(next[i] >= 0 && next[i] < 2 * k && nowt + 1 < t[next[i]]) {
				q.push(next[i]); t[next[i]] = nowt + 1;
			}
			q.pop();
		}
		printf("%d\n",t[k]);
	}
	return 0;
}
