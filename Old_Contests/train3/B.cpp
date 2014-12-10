#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int rr[3][3] = {
    0,1,2,1,2,0,2,0,1
};

const int maxn = 50000 + 5;

int N,K,p[maxn],r[maxn];
const int rp[3][3] = {
    0,2,1,1,0,2,2,1,0
};

void init() {
    for(int i = 1;i <= N;i++) {
        p[i] = i; r[i] = 0;
    }
}

int findset(int i) {
    if(p[i] == i) return i;
    int gg = findset(p[i]);
    r[i] = (r[i] + r[p[i]]) % 3;
    return p[i] = gg;
}

int main() {
    scanf("%d%d",&N,&K);
    int ans = 0;
    init();
    for(int i = 0;i < K;i++) {
        int d,x,y;
        scanf("%d%d%d",&d,&x,&y);
        if(x > N || y > N || (d == 2 && x == y)) {
            ans++;
        } else {
            int px = findset(x),py = findset(y);
            if(px == py) {
                if(d == 1 && r[x] != r[y]) {
                    ans++;
                }
                if(d == 2 && r[x] != (r[y] + 1) % 3) {
                    ans++;
                }
            } else {
                p[px] = y;    
                r[px] = rp[d-1][r[x]];
                findset(x);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

