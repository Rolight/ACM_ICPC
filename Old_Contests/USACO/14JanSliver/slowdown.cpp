#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 10001;
int n,tevent[maxn],devent[maxn],tcount,dcount;

int main() {
	FILE *in = fopen("slowdown.in","r"),*out = fopen("slowdown.out","w");
	int val,pt = 0,pd = 0,sec = 0,spd=  1;
	double dis = 0;
	char cmd;
	fscanf(in,"%d",&n);
	for(int i = 0;i < n;i++) {
		fscanf(in," %c%d",&cmd,&val);
		if(cmd == 'T') tevent[tcount++] = val;
		else devent[dcount++] = val;
	}
	sort(tevent,tevent + tcount);
	sort(devent,devent + dcount);
	while(dis < 1000) {
		dis += 1.0 / spd;
		sec++;
		if(pt < tcount && sec == tevent[pt]) spd++,pt++;
		if(pd < dcount && dis == devent[pd]) spd++,pd++;
	}
	fprintf(out,"%d\n",sec);
	fclose(in); fclose(out);
	return 0;
} 
