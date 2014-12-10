#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
const int maxn = 70;
int start[maxn],finish[maxn];

LL f(int P[],int i,int fin) {
	if(i == 0) return 0;
	if(P[i] == fin) return f(P,i - 1,fin);
	return f(P,i - 1,6 - P[i] - fin) + 1 + (1LL << (i - 1)) - 1;
}

int main() {
	int n,kase = 1;
	while(scanf("%d",&n),n) {
		LL ans = 0LL;
		for(int i = 1;i <= n;i++) {
			scanf("%d",&start[i]);
		}
		for(int i = 1;i <= n;i++) {
			scanf("%d",&finish[i]);
		}
		for(int i = n;i >= 1;i--) if(start[i] != finish[i]) {
			ans = f(start,i - 1,6 - start[i] - finish[i]) + f(finish,i - 1,6 - start[i] - finish[i]) + 1;
			break;
		}
		cout << "Case " << kase << ": " << ans << endl;
		kase++;
	}
	return 0;
}
