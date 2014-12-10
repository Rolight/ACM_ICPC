#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

const int maxq = 2e3 + 10;
const int maxn = 1e6 + 10 + maxq;

int sum[maxn << 2];

void build(int rt,int l,int r) {
    if(l == r) sum[rt] = 1;
    else {
        int mid = (l + r) >> 1;
        build(lson); build(rson);
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }
}

void update(int rt,int l,int r,int pos,int tar) {
    if(l == r) sum[rt] = tar;
    else {
        int mid = (l + r) >> 1;
        if(pos <= mid) update(lson,pos,tar);
        else update(rson,pos,tar);
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }
}

int query(int rt,int l,int r,int val) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(sum[rt << 1] >= val) return query(lson,val);
    else return query(rson,val - sum[rt << 1]);
}

char str[maxn],str1[maxn],cmd[maxq],val[maxq];
int q,n,len,pos[maxq],rpos[maxn],icnt[maxq];


int main() {
    scanf("%s",str);
    len = strlen(str);
    scanf("%d",&q);
    icnt[0] = len;
    for(int i = 1;i <= q;i++) {
        scanf(" %c",&cmd[i]);
        if(cmd[i] == 'I') {
            scanf(" %c%d",&val[i],&pos[i]);
            icnt[i] = icnt[i - 1] + 1;
        }
        else {
            scanf("%d",&pos[i]);
            icnt[i] = icnt[i - 1];
        }
    }

    n = icnt[q];
    //printf("n is %d\n",n);
    build(1,1,n);
    //倒着插入所有的字符
    for(int i = q;i >= 1;i--) if(cmd[i] == 'I') {
        pos[i] = min(pos[i],icnt[i]);
        rpos[i] = query(1,1,n,pos[i]);
        update(1,1,n,rpos[i],0);
        str1[rpos[i]] = val[i];
    }

    for(int i = 1, zcnt = 0;i <= n;i++) {
        if(str1[i] == 0) {
            str1[i] = str[zcnt++];
            //update(1,1,n,i,1);
        }
    }
    /*
       for(int i = 1;i <= n;i++) {
       printf("%c",str1[i]);
       }
       putchar('\n');
       */
    //顺序查询
    for(int i = 1;i <= q;i++) {
        if(cmd[i] == 'Q') {
            int ret = query(1,1,n,pos[i]);
            printf("%c\n",str1[ret]);
        }
        else {
            update(1,1,n,rpos[i],1);
        }
    }
    return 0;
}
