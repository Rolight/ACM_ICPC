#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 50001;

int p[maxn],r[maxn];
int r1[3][3] = {
    0,1,2,1,2,0,2,0,1
};
int r2[3][3] = {
    0,1,2,2,0,1,1,2,0
};

int findset(int i) {
    if(i == p[i]) {
        r[i] = 0; return i;
    }
    int root = findset(p[i]);
    r[i] = r1[r[i]][r[p[i]]];
    return p[i] = root;
}

int main() {
    int n,k,d,x,y,ans = 0;;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++) {
        r[i] = 0; p[i] = i;
    }
    while(k--) {
        scanf("%d%d%d",&d,&x,&y);
        if(x < 1 || x > n || y < 1 || y > n) ans++;
        else {
            int px = findset(x),py = findset(y);
            if(d == 1) {
                if(px != py) { //x和y不在一个集合里面
                    p[px] = y; r[px] = r2[r[x]][0];
                    findset(x);
                } else if(r[x] != r[y]) ans++;
            } else {
                if(px != py) {
                    p[px] = y; r[px] = r2[r[x]][1];
                    findset(x);
                } else if(r[x] != (r[y] + 1) % 3) ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
