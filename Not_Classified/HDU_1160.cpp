#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Mice {
	int w,s,i;
};

const int maxn = 1005;

Mice mice[maxn];
bool cmp(Mice a,Mice b) {
	return a.w > b.w;
}

int f[maxn];

void print_ans(int now) {
	printf("%d\n",mice[now].i);
	if(f[now] == 1) return;
	for(int i = 1;i < now;i++) if(mice[now].s > mice[i].s && mice[now].w != mice[i].w) {
		if(f[i] == f[now] - 1) {
			print_ans(i);
			break;
		}
	}
}

int main() {
	int n = 0;
	while(scanf("%d%d",&mice[n + 1].w,&mice[n + 1].s) == 2) mice[n].i = ++n;
	sort(mice + 1,mice + n + 1,cmp);
	
	int ans = 0,ansi;
	for(int i = 1;i <= n;i++) {
		f[i] = 1;
		for(int j = i - 1;j >= 1;j--) 
			if(mice[j].s < mice[i].s && mice[j].w != mice[i].w) {
				f[i] = max(f[j] + 1,f[i]);
			}
		ans = max(ans,f[i]);
		if(ans == f[i]) ansi = i;
	}
	printf("%d\n",ans);
	print_ans(ansi);
	return 0;
}
