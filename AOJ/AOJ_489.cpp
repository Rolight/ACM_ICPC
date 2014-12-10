#include<cstdio>

const int maxn = 1000000 + 5;
int f[maxn];
int findp(int x) {
    return x == f[x] ? x : f[x] = findp(f[x]);
}

int main(){
    int n, x;
    int sum = 0;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++) f[i] = i;
    for(int i = 1; i <= n; i++){
        scanf("%d",&x);
        int pa = findp(x),pb = findp(i);
        if(pa != pb) f[pa] = pb;
    }
    for(int i = 1;i <= n;i++) if(i == findp(i)) sum++;
    printf("%d\n", sum);
    return 0;
}
