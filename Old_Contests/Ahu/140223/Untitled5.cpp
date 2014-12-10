#include <cstdio>
#include <cstring>
#include <map>

struct date {
    int a,b,c;
    date(int y,int m,int d) {
        a = y;b = m;c = d;
    }
};

bool operator < (date a,date b) {
    if(a.a != b.a) return a.a < b.a;
    if(a.b != b.b) return a.b < b.b;
    return a.c < b.c;
}

using namespace std;
const int maxn = 100001;
char str[maxn],s[maxn];
map<date,int> t;
int ml[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};


int main() {
    scanf("%s",str);
    int l,len = 0;
    l = strlen(str);
    for(int i = 0;i < l;i++) {
        if(str[i] != '-') s[len++] = str[i];
        else if(s[len - 1] != ' ' && i) s[len++] = '*';
    }
    int i = 0;
    while(s[i] != '*') i++;
    for(;i < len;i++) {
        int a,b,c;
        a = b = c = -1;
        sscanf(s + i - 2,"%02d*%02d*%04d",&a,&b,&c);
        //printf("%d %d %d\n",a,b,c);
        if(b >= 1 && b <= 12 && c >= 2013 && c <= 2015 && a <= ml[b] && a > 0)
            t[date(a,b,c)]++;
        i++;
        while(s[i] != '*' && i < len) i++;
        i--;
    }
    map<date,int>::iterator mm = t.begin();
    for(map<date,int>::iterator it = t.begin();it != t.end();++it) if(it->second > mm->second) {
        mm = it;
    }
    date n = mm->first;
    printf("%02d-%02d-%04d\n",n.a,n.b,n.c);
    return 0;
}
