#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Item {
	int s,b;
	Item(int ss,int bb):s(ss),b(bb) {}
	bool operator< (const Item& x) const { return s > x.s; }
};

const int maxn = 751;
int A[maxn][maxn];

int main() {
	int k;
	while(~scanf("%d",&k)) {
		for(int i = 0;i < k;i++) {
			for(int j = 0;j < k;j++) {
				scanf("%d",&A[i][j]);
			}
			sort(A[i],A[i] + k);
		}
		for(int i = 1;i < k;i++) {
			priority_queue<Item> q;
			for(int j = 0;j < k;j++) q.push(Item(A[0][j] + A[i][0],0));
			for(int j = 0;j < k;j++) {
				Item r = q.top(); q.pop();
				A[0][j] = r.s;
				if(r.b + 1 < k) {
					r.s = r.s - A[i][r.b] + A[i][r.b + 1];
					r.b++;
					q.push(r);
				}
			}
		}
		printf("%d",A[0][0]);
		for(int i = 1;i < k;i++) printf(" %d",A[0][i]);
		putchar('\n');
	}
	return 0;
}
