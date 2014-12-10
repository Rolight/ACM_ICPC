/*
ID: flsnnx1
LANG: C++
TASK: lamps
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N;
bool s[105],on[105],off[105];

vector<vector<bool> > vb;

void ch1() {
    for(int i = 1;i <= N;i++) s[i] = !s[i];
}

void ch2() {
    for(int i = 1;i <= N;i += 2) s[i] = !s[i];
}

void ch3() {
    for(int i = 2;i <= N;i += 2) s[i] = !s[i];
}

void ch4() {
    for(int i = 1;i <= N;i += 3) s[i] = !s[i];
}

void init() {
    for(int i = 1;i <= N;i++) s[i] = true;
}

typedef void (*function)();
function fun[4] = {ch1,ch2,ch3,ch4};

int main() {
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    int C; scanf("%d%d",&N,&C);
    for(int i = 0;i <= 15;i++) {
        int cnt = 0;
        for(int j = 0;j < 4;j++) if(i & (1 << j)) cnt++;
        if(cnt % 2 == C % 2 && cnt <= C) {
            init();
            for(int j = 0;j < 4;j++) if(i & (1 << j)) {
                (fun[j])();
            }
            vb.push_back(vector<bool>(s + 1,s + N + 1));
        }
    }
    int tmp;
    while(scanf("%d",&tmp),tmp != -1) on[tmp - 1] = true;
    while(scanf("%d",&tmp),tmp != -1) off[tmp - 1] = true;
    sort(vb.begin(),vb.end());
    int m = vb.size(),cnt_ans = 0;
    for(int i = 0;i < m;i++) {
        bool ok = true;
        for(int j = 0;j < N && ok;j++) {
            if(on[j] == true && vb[i][j] == false) ok = false;
            if(off[j] == true && vb[i][j] == true) ok = false;
        }
        if(ok) {
            cnt_ans++;
            for(int j = 0;j < N;j++) {
                printf("%d",vb[i][j] ? 1 : 0);
            }
            putchar('\n');
        }
    }
    if(cnt_ans == 0) puts("IMPOSSIBLE");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
