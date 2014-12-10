#include <cstdio>
#include <cstring>

using namespace std;

char a[15],b[15],c[15];
char na[15],nb[15],nc[15];

void nozero(char *src,char *dest) {
	int len = strlen(src),j = 0;
	for(int i = 0;i < len;i++) if(src[i] != '0') dest[j++] = src[i];
	dest[j] = 0;
}

void addto(char *sa,char *sb,char *ans) {
	int lena = strlen(sa),lenb = strlen(sb),ia[15],ib[15];
	memset(ia,0,sizeof(ia));
	memset(ib,0,sizeof(ib));
	for(int i = 0;i < lena;i++) ia[lena - i - 1] = sa[i] - '0';
	for(int i = 0;i < lenb;i++) ib[lenb - i - 1] = sb[i] - '0';
	int len = lena > lenb ? lena : lenb;
	for(int i = 0;i < len;i++) {
		ia[i] += ib[i];
		ia[i + 1] += ia[i] / 10;
		ia[i] %= 10;
	}
	if(ia[len]) len++;
	for(int i = 0;i < len;i++) ans[len - i - 1] = ia[i] + '0';
	ans[len] = 0;
}

int main() {
	scanf("%s%s",a,b);
	addto(a,b,c);
	nozero(a,na);
	nozero(b,nb);
	nozero(c,nc);
	addto(na,nb,c);
	if(strcmp(c,nc)) printf("NO\n");
	else printf("YES\n");
	return 0;
}
