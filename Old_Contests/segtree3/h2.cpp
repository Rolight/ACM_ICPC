#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100001;

int c[maxn << 2],a[maxn],ans[maxn],n,m;

inline int lowbit(int x){
    return x & (-x);
}
int sum(int m){
    int sum = 0;
    while(m > 0){
        sum += c[m];
        m -= lowbit(m);
    }
    return sum;
}
inline int ins(int i,int num){
    while(i <= n + maxn - 1){
        c[i] += num;
        i += lowbit(i);
    }
}

int main(){
    int T,num;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(int i = 1;i <= n;i++) a[i]=i +maxn - 1;
        for(int i = 2;i <= n;i++) ins(i + maxn - 1,1);
        for(int i = 1;i <= m;i++){
            scanf("%d",&num);
            ans[i] = sum(a[num]);
            ins(a[num],-1);
            ins(maxn - i + 1,1);
            a[num] = maxn - i;
        }
        for(int i = 1;i <= m;i++)
        if(i != m) printf("%d ",ans[i]);
        else printf("%d\n",ans[i]);
    }
}
