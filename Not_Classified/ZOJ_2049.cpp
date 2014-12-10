#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1005;
const int maxv = 20000 + 5;
bool vis[maxv];

struct Segment {
    int l,r;
    Segment(int l = 0,int r = 0):l(l),r(r) {
    }
    bool operator < (const Segment &x) const {
        if(r == x.r) return l < x.l;
        return r < x.r;
    }
};

void swap(int &a,int &b) {
    int t = a; a = b;b = t;
}

Segment seg[maxn];
vector<int> ans;

int main() {
    int T; scanf("%d",&T);
    bool first = true;
    while(T--) {
        int n,k;
        ans.clear();
        scanf("%d%d",&k,&n);
        if(first) first = false;
        else putchar('\n');
        memset(vis,0,sizeof(vis));
        for(int i = 0;i < n;i++) {
            scanf("%d%d",&seg[i].l,&seg[i].r);
            seg[i].l += 10000;
            seg[i].r += 10000;
            if(seg[i].l > seg[i].r) swap(seg[i].l,seg[i].r);
        }
        sort(seg,seg + n);
        for(int i = 0;i < n;i++) {
            int cnt = 0;
            for(int j = seg[i].r;j >= seg[i].l;j--) {
                if(vis[j]) cnt++;
                if(cnt >= k) break;
            }
            if(cnt < k) {
                for(int j = seg[i].r;j >= seg[i].l;j--) {
                    if(!vis[j]) {
                        vis[j] = true;
                        ans.push_back(j - 10000);
                        cnt++;
                    }
                    if(cnt >= k) break;
                }
            }
        }
        printf("%d\n",ans.size());
        int m = ans.size();
        for(int i = 0;i < m;i++) printf("%d\n",ans[i]);
    }
    return 0;
}
