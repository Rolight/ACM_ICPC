#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct task {
    int time,reduce;
};

bool cmp(task a,task b) {
    if(a.reduce == b.reduce) return a.time < b.time;
    return a.reduce > b.reduce;
}

const int maxn = 1005;
task t[maxn];
int arrange[maxn];

int main() {
    int T,N; scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for(int i = 0;i < N;i++) scanf("%d",&t[i].time);
        for(int i = 0;i < N;i++) scanf("%d",&t[i].reduce);
        sort(t,t + N,cmp);
        memset(arrange,-1,sizeof(arrange));
        int ans = 0;
        for(int i = 0;i < N;i++) {
            if(arrange[t[i].time] == -1) arrange[t[i].time] = i;
            else {
                int pos = t[i].time;
                while(pos > 0 && arrange[pos] != -1) pos--;
                if(pos == 0) ans += t[i].reduce;
                else arrange[pos] = i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

