#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char a[300],b[300];
int o[601],n;
stack<char> s;

void dfs(int p,int s1,int s2) {
   if(p == n * 2 && s2 == n) {
       for(int i = 0;i < n * 2;i++) {
           if(o[i] == 0) putchar('o');
           else putchar('i');
           putchar(' ');
       }
       printf("\n");
   }
   if(p == n * 2) return;
   if(s1 != n) {
       s.push(a[s1]);
       o[p] = 1;
       dfs(p + 1,s1 + 1,s2);
       s.pop();
   }
   if(!s.empty()) {
       char t = s.top();
       if(t == b[s2]) {
           s.pop();
           o[p] = 0;
           dfs(p + 1,s1,s2 + 1);
           s.push(t);
       }
   }
}

int main() {
    while(~scanf("%s%s",a,b)) {
        int lena = strlen(a),lenb = strlen(b);
        if(lena != lenb) printf("[\n]\n");
        else {  
            n = lena;
            printf("[\n");
            dfs(0,0,0);
            printf("]\n");
        }
    }
    return 0;
}
