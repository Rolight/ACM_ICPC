#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N,M,Y;
struct obj {
    int k,id,x;
    double v;
    bool operator < (const obj &x) const {
        return v < x.v;
    }
};

bool cmp(obj a,obj b) {
    return a.id < b.id;
}

const int maxn = 1000 + 5;
obj a[maxn];
priority_queue<obj> q;

int main() {
    int T;
    bool first = true;
    scanf("%d",&T);
    while(T--) {
        if(first) first = false;
        else putchar('\n');
        scanf("%d%d%d",&N,&M,&Y);
        int rest = M;
        memset(a,0,sizeof(a));
        for(int i = 1;i <= N;i++) {
            obj tmp; scanf("%d",&tmp.x);
            tmp.id = i;
            tmp.k = (double)tmp.x / Y * M;
            tmp.v = (double)tmp.x / Y - ((double)tmp.k / M);
            rest -= tmp.k;
            q.push(tmp);
            //printf("%lf %d %d\n",tmp.v,tmp.id,tmp.k);
        }
        while(rest > 0) {
            rest--;
            obj tmp = q.top(); q.pop();
            tmp.v -= 1.0f / Y;
            tmp.k++;
            q.push(tmp);
        }
        for(int i = 0;i < N;i++) {
            a[i] = q.top();
            q.pop();
        }
        sort(a,a + N,cmp);
        for(int i = 0;i < N;i++) {
            if(i > 0) putchar(' ');
            printf("%d",a[i].k);
        }
        putchar('\n');
    }
    return 0;
}

