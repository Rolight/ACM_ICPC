#include <cstdio>
#include <cstring>

char ch[100001];

int main() {
    gets(ch);
    int len = strlen(ch);
    int zero = 0,one = 0,str = 0;
    for(int i = 0;i < len;i++) {
        if(ch[i] == '0') zero++;
        else one++;
        if(zero == 1) {
            ch[i] = -1; break;
        }
    }
    //printf("%d %d\n",zero,one);
    if(zero == 0) len--;
    if(len == 0) puts("0");
    for(int i = 0;i < len;i++) if(ch[i] != -1) putchar(ch[i]);
    putchar('\n');
    return 0;
}
