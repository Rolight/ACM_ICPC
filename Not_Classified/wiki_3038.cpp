#include<stdio.h>
int w(int n,int t){while(++t,n!=1)n=(n&1)?(3*n+1):(n/2);return t;}int main(){int t,n;scanf("%d",&t);while(t--){scanf("%d",&n); printf("%d\n",w(n,0)-1);}return 0;}
