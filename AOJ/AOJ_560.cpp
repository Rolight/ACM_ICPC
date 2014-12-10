#include <cstdio>
#include <cstring>
#include <algorithm>

#define Win 0
#define Lose 1

using namespace std;

int S[11],N,M;
char note[100001][2];

inline char dp() {
	int n,p,i,j;
	for(i = 0;i < S[0];i++) note[i][0] = note[i][1] = Lose;
	for(i = S[0];i <= N;i++) {
		note[i][0] = note[i][1] = 0;
		for(j = 0;j < M && S[j] <= i;j++) {
			note[i][0] |= note[i - S[j]][1];
			note[i][1] |= note[i - S[j]][0];
		}
		note[i][0] ^= 1; note[i][1] ^= 1;
	}
	return note[N][0];
}

int main() {
	int c = 1;
	while(scanf("%d%d",&N,&M),M || N) {
		for(int i = 0;i < M;i++) scanf("%d",S + i);
		sort(S,S + M);
		char ret = dp();
		printf("Case %d:\n",c++);
		if(ret == Win) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
