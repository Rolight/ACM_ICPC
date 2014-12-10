#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000;

int f[maxn][maxn];

int main() {
	char a[maxn],b[maxn];
	while(~scanf("%s%s",a,b)) {
		memset(f,0,sizeof(f));
		int lena = strlen(a),lenb = strlen(b);
		for(int i = 1;i <= lena;i++) {
			for(int j = 1;j <= lenb;j++) {
				if(a[i - 1] == b[j - 1]) 
					f[i][j] = f[i - 1][j - 1] + 1;
				else f[i][j] = max(f[i - 1][j],f[i][j - 1]);
			}
		}
		printf("%d\n",f[lena][lenb]);
	}
	return 0;
}
