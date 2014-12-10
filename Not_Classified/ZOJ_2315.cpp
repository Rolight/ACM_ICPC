#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 500000 + 5;

struct Node {
   int cnt,p,id;
   bool operator < (const Node &x) const {
       return id > x.id;
   }
};

Node a[maxn];
vector<int> anst;
bool flag[maxn];

int main() {
    int T; scanf("%d",&T);
    bool first = true;
    while(T--) {
        if(first) first = false;
        else putchar('\n');
        int n,ans = 0;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(flag,0,sizeof(flag));
        a[1].id = 1;
        for(int i = 2;i <= n;i++) {
            int tmp;
            scanf("%d",&tmp);
            a[tmp].cnt++;
            a[i].p = tmp;
            a[i].id = i;
        }
        sort(a + 1,a + 1 + n);
        anst.clear();
        for(int i = 1;i <= n;i++) {
            if(a[i].id != 1 && flag[a[i].p] == 0 
                    && flag[a[i].id] == 0) {
                ans += 1000; anst.push_back(a[i].id);
                flag[a[i].p] = 1;
                flag[a[i].id] = 1;
            }
        }
        printf("%d\n",ans);
        sort(anst.begin(),anst.end());
        int m = anst.size();
        for(int i = 0;i < m;i++) {
            if(i > 0) putchar(' ');
            printf("%d",anst[i]);
        }
        putchar('\n');
    }
    return 0;
}

