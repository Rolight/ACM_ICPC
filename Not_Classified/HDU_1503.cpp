#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;

char sa[maxn],sb[maxn];
char ans[maxn * 2];
int f[maxn][maxn];
int posa[maxn],posb[maxn];
int maxlen;

void draw(int x,int y) {
	if(maxlen == 0) return;
	for(int i = x;i >= 1;i--) {
		for(int j = y;j >= 1;j--) {
			if(f[i][j] == f[x][y] && f[i][j] == f[i - 1][j - 1] + 1 && sa[i] == sb[j]) {
				posa[maxlen] = i;
				posb[maxlen] = j;
				maxlen--;
				draw(i - 1,j - 1);
				return;
			}
		}
	}
}

int main() {
	while(scanf("%s%s",sa + 1,sb + 1) == 2) {
		int lena = strlen(sa + 1),lenb = strlen(sb + 1);
		memset(f,0,sizeof(f));
		for(int i = 1;i <= lena;i++) {
			for(int j = 1;j <= lenb;j++) {
				if(sa[i] == sb[j]) {
					f[i][j] = f[i - 1][j - 1] + 1;
				} else {
					f[i][j] = max(f[i - 1][j],f[i][j - 1]);
				}
			}
		}
		maxlen = f[lena][lenb];
		posa[maxlen + 1] = posb[maxlen + 1] = 210000000;
		draw(lena,lenb);
		int pa = 1,pb = 1,ea = 1,eb = 1;
		int nowlen = 0;
		while(1) {
		//	printf("\n%d %d %d %d %d %d\n",pa,pb,ea,eb,posa[ea],posb[eb]);
			if(nowlen == lena + lenb - f[lena][lenb]) break;
			if(pa < posa[ea] && pa <= lena) putchar(sa[pa++]),nowlen++;
			if(pb < posb[eb] && pb <= lenb) putchar(sb[pb++]),nowlen++;
			if(pa == posa[ea] && pb == posb[eb]) {
				nowlen++; putchar(sa[pa]);
				pa++; pb++; ea++; eb++;
			}
		}
		putchar('\n');
	}
	return 0;
}
