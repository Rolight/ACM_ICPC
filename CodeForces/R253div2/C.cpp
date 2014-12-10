#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>


using namespace std;

int c_ch[5],c_num[5];
int n;
char val[200][5];
int cv[200],nv[200];

inline int mp(char c) {
    switch(c) {
        case 'B': return 0;
        case 'Y': return 1;
        case 'W': return 2;
        case 'G': return 3;
        case 'R': return 4;
    }
}

int count() {
    int sum = n;
    for(int i = 1;i <= n;i++) {
        if(cv[i] + nv[i] == 0) sum--;
        else if(cv[i] + nv[i] == 1) {
            if(nv[i] == 1 && c_num[val[i][1] - '1'] == 1) {
                sum--;
                c_num[val[i][1] - '1']  = 0;
            }
            if(cv[i] == 1 && c_ch[mp(val[i][0])] == 1) {
                c_ch[mp(val[i][0])] = 0;
                sum--;
            }
        }
    }
    return sum;
}

int getmax(int *arr) {
    int maxi,maxv = -1;
    for(int i = 0;i < 5;i++) {
        if(arr[i] > maxv) {
            maxv = arr[i];
            maxi = i;
        }
    }
    return maxi;
}

int main() {
    scanf("%d",&n);
    int rest = n;
    for(int i = 1;i <= n;i++) {
        scanf("%s",val[i]);
        c_ch[mp(val[i][0])]++;
        c_num[val[i][1] - '1']++;
        cv[i] = nv[i] = 1;
    }
    for(int i = 0;i < 5;i++) {
        c_ch[i] %= n;
        c_num[i] %= n;
    }
    int ans = 0;
    int maxc = getmax(c_ch),maxn = getmax(c_num);
    if(c_ch[maxc] == c_num[maxn] && c_ch[maxc] == 0) {
        puts("0"); return 0;
    }
    while(count() > 0) {
        int maxc = getmax(c_ch),maxn = getmax(c_num);
        if(c_ch[maxc] == c_num[maxn] && c_ch[maxc] == 0) {
            break;
        }
        for(int i = 1;i <= n;i++) {
            if(c_ch[maxc] > c_num[maxn]) {
                if(mp(val[i][0]) == maxc) cv[i] = 0;
            }
            else {
                if(val[i][1] - '1' == maxn) nv[i] = 0;
            }
        }           
        if(c_ch[maxc] > c_num[maxn]) {
            c_ch[maxc] = 0;
        } else c_num[maxn] = 0;
        ans++;
    }
    printf("%d\n",ans - 1);
    return 0;
}
