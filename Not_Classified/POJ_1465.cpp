#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>


using namespace std;

int N,M,num[1000];
int val[5555],pre[5555];
int len[5555],res[5555];
bool tab[5555];

bool notzero(int id) {
    return !(len[id] == 1 && val[id] == 0);
}

void print_path(int now) {
    if(~pre[now]) print_path(pre[now]);
    putchar(val[now] + '0');
}

int main() {
    while(scanf("%d%d",&N,&M) != EOF) {
        memset(tab,0,sizeof(tab));
        for(int i = 0;i < M;i++) {
            scanf("%d",&num[i]);
        }
        sort(num,num + M);
        if(N == 0) {
            puts("0"); continue;
        }
        int front = 0,rear = 0;
        for(int i = 0;i < M;i++) {
            len[rear] = 1;
            res[rear] = num[i] % N;
            pre[rear] = -1;
            val[rear] = num[i];
            rear++;
            if(num[i] != 0) {
                tab[num[i] % N] = true;
            }
        }
        int ans = 0;
        while(front < rear) {
            int now = front; front++; 
            if(res[now] == 0 && notzero(now)) {
                ans = now; break;
            }           
            for(int i = 0;i < M;i++) {
                if(!notzero(now) && num[i] == 0) continue;
                int nres = (res[now] * 10 % N + num[i] % N) % N;
                if(tab[nres] == false) {
                    tab[nres] = true;
                    len[rear] = len[now] + 1;
                    res[rear] = nres;
                    pre[rear] = now;
                    val[rear] = num[i];
                    rear++;
                }
            }
        }
        if(ans == 0) puts("0");
        else {
            print_path(ans);
            putchar('\n');
        }
    }
    return 0;
}
