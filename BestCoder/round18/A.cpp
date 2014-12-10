#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1e4 + 10;
bool vis[maxn];
vector<int> pnum;

void init() {
    vis[1] = true;
    int maxv = 10000;
    for(int i = 2; i <= maxv; i++) if(!vis[i]) {
        pnum.push_back(i);
        for(int j = i + i; j <= maxv; j += i) vis[j] = true;
    }
}

void gao(int num) {
    int ans = 0;
    int msize = pnum.size();
    for(int i = 0; i < msize; i++) {
        for(int j = i; j < msize && pnum[i] + pnum[j] < num; j++) {
            int tt = num - pnum[i] - pnum[j];
            if(!vis[tt] && tt >= pnum[j]) ans++;
            if(tt < pnum[j]) break;
        }
    }
    printf("%d\n", ans);
}

int main() {
    init();
    int n;
    while(scanf("%d", &n) != EOF) {
        gao(n);
    }
    return 0;
}
