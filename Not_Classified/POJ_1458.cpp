#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 1024;
char a[maxn],b[maxn];
int f[maxn][maxn];

int main() {
    while(scanf("%s%s",a + 1,b + 1) != EOF) {
        memset(f,0,sizeof(f));
        int lena = strlen(a + 1),lenb = strlen(b + 1);
        for(int i = 1;i <= lena;i++) {
            for(int j = 1;j <= lenb;j++) {
                if(a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
                else f[i][j] = max(f[i - 1][j],f[i][j - 1]);
            }
        }
        printf("%d\n",f[lena][lenb]);
    }
    return 0;
}
