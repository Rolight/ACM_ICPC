#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

#define lson rt<<1,l,mid
#define rson rt<<1|1,mid + 1,r
typedef long long LL;
const int maxn = 50000 + 5;
int lmax[maxn << 2],rmax[maxn << 2],mmax[maxn << 2];
int strv[maxn << 2],endv[maxn << 2],lazy_str[maxn << 2],lazy_end[maxn << 2],lazy[maxn << 2];
int sum[maxn << 2],lazy_add[maxn << 2];
int N,M;

void pushdown_sum(int rt,int l,int r) {
    if(lazy_add[rt] == -1) return;
    int lc = rt<<1,rc = rt<<1|1,mid = (l + r) >> 1;
    int Llen = mid - l + 1,Rlen = r - mid;
    lazy_add[lc] = lazy_add[rt]; lazy_add[rc] = lazy_add[rt];
    sum[lc] = lazy_add[rt] * Llen; sum[rc] = lazy_add[rt] * Rlen;
    lazy_add[rt] = -1;
}

void update_sum(int rt,int l,int r,int ql,int qr,int v) {
    if(ql <= l && qr >= r) {
        lazy_add[rt] = v; sum[rt] = v * (r - l + 1);
    }
    else {
        int mid = (l + r) >> 1,lc = rt << 1,rc = rt << 1 | 1;
        pushdown_sum(rt,l,r);
        if(ql <= mid) update_sum(lson,ql,qr,v);
        if(qr > mid) update_sum(rson,ql,qr,v);
        sum[rt] = sum[lc] + sum[rc];
    }
}

int getstr(int rt,int l,int r,int Val) {
    if(l == r) return l;
    int lc = rt<<1,rc = rt<<1|1,mid = (l + r) >> 1;
    pushdown_sum(rt,l,r);
    if(sum[lc] >= Val) return getstr(lson,Val);
    return getstr(rson,Val - sum[lc]);
}

void pushup(int rt,int l,int r) {
    int lc = rt<<1,rc = rt<<1|1,mid = (l + r) >> 1;
    int Llen = mid - l + 1,Rlen = r - mid;
    lmax[rt] = lmax[lc]; rmax[rt] = rmax[rc]; mmax[rt] = max(mmax[lc],mmax[rc]);
    if(rmax[lc] != 0 && lmax[rc] != 0) {
        if(lmax[lc] == Llen) lmax[rt] += lmax[rc];
        if(rmax[rc] == Rlen) rmax[rt] += rmax[lc];
        mmax[rt] = max(mmax[rt],rmax[lc] + lmax[rc]);
        mmax[rt] = max(mmax[rt],max(lmax[rt],rmax[rt]));
    }
}

void pushdown(int rt,int l,int r) {
    if(lazy[rt] == -1) return;
    int lc = rt<<1,rc = rt<<1|1,mid = (l + r) >> 1;
    int Llen = mid - l + 1,Rlen = r - mid;
    lazy[lc] = lazy[rc] = lazy[rt];
    lmax[lc] = rmax[lc] = mmax[lc] = lazy[rt] ? 0 : Llen;
    lmax[rc] = rmax[rc] = mmax[rc] = lazy[rt] ? 0 : Rlen;
    lazy[rt] = -1;
}

void update(int rt,int l,int r,int ql,int qr,int v) {
    if(ql <= l && qr >= r) {
        lazy[rt] = v;
        lmax[rt] = rmax[rt] = mmax[rt] = v ? 0 : r - l + 1;
    }
    else {
        int mid = (l + r) >> 1;
        pushdown(rt,l,r);
        if(ql <= mid) update(lson,ql,qr,v);
        if(qr > mid) update(rson,ql,qr,v);
        pushup(rt,l,r);
    }
}

int query(int rt,int l,int r,int D) {
    int lc = rt<<1,rc = rt<<1|1,mid = (l + r) >> 1;
    pushdown(rt,l,r);
    if(lmax[rt] >= D) return l;
    if(mmax[rt<<1] >= D) return query(lson,D);
    if(rmax[lc] + lmax[rc] >= D) return (l + r) / 2 - rmax[lc] + 1;
    return query(rson,D);
}

void update_seg(int rt,int l,int r,int ql,int qr,int v,int *lazy,int *Val) {
    if(ql <= l && qr >= r) lazy[rt] = Val[rt] = v; 
    else {
        if(lazy[rt] != -1) lazy[rt<<1] = lazy[rt<<1|1] = Val[rt<<1] = Val[rt<<1|1] = lazy[rt],lazy[rt] = -1;
        int mid = (l + r) >> 1;
        if(ql <= mid) update_seg(lson,ql,qr,v,lazy,Val);
        if(qr > mid) update_seg(rson,ql,qr,v,lazy,Val);
    }
}

int query_seg(int rt,int l,int r,int p,int *lazy,int *Val) {
    if(l == r) return Val[rt];
    if(lazy[rt] != -1) lazy[rt<<1] = lazy[rt<<1|1] = Val[rt<<1] = Val[rt<<1|1] = lazy[rt],lazy[rt] = -1;
    int mid = (l + r) >> 1;
    if(p <= mid) return query_seg(lson,p,lazy,Val);
    if(p > mid) return query_seg(rson,p,lazy,Val);
}

char buf[1024];

void Handle() {
    int len,pos;
    scanf("%s",buf);
    if(buf[0] == 'N') {
        scanf("%d",&len);
        if(mmax[1] < len) {
            puts("Reject New"); return;
        }
        int ret = query(1,1,N,len);
        printf("New at %d\n",ret);
        update(1,1,N,ret,ret + len - 1,1);
        update_seg(1,1,N,ret,ret + len - 1,ret,lazy_str,strv);
        update_seg(1,1,N,ret,ret + len - 1,ret + len - 1,lazy_end,endv);
        update_sum(1,1,N,ret,ret,1);
    }
    if(buf[0] == 'G') {
        scanf("%d",&pos);
        if(sum[1] < pos) {
            puts("Reject Get"); return;
        }
        int ret = getstr(1,1,N,pos);
        printf("Get at %d\n",ret);
    }
    if(buf[0] == 'R') {
        puts("Reset Now");
        update(1,1,N,1,N,0);
        update_seg(1,1,N,1,N,0,lazy_str,strv); 
        update_seg(1,1,N,1,N,0,lazy_end,endv);
        update_sum(1,1,N,1,N,0);
    }
    if(buf[0] == 'F') {
        scanf("%d",&pos);
        int spos = query_seg(1,1,N,pos,lazy_str,strv);
        int epos = query_seg(1,1,N,pos,lazy_end,endv);
        if(spos <= 0) {
            puts("Reject Free"); return;
        }
        printf("Free from %d to %d\n",spos,epos);
        update(1,1,N,spos,epos,0);
        update_seg(1,1,N,spos,epos,0,lazy_str,strv);
        update_seg(1,1,N,spos,epos,0,lazy_end,endv);
        update_sum(1,1,N,spos,spos,0);
    }
}

int main() {
    while(scanf("%d%d",&N,&M) != EOF) {
        update(1,1,N,1,N,0);
        update_seg(1,1,N,1,N,0,lazy_str,strv); 
        update_seg(1,1,N,1,N,0,lazy_end,endv);
        update_sum(1,1,N,1,N,0);
        for(int i = 0;i < M;i++) Handle();
        puts("");
    }
    return 0;
}

