#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

const int maxn = 2;
const int maxp = 2005;

struct Block {
	char data[maxn];
	int len;
	Block *next, *prev;
};

struct Curor {
	Block *bk;
	int gpos;
	Curor(Block *bk = NULL, int gpos = 0): bk(bk), gpos(gpos) {}
};

//块池
Block ck[maxp];
int sz, ggpos;

Block *newBlock() {
	ck[sz].len = 0;
	ck[sz].next = NULL;
	ck[sz].prev = NULL;
	return &ck[sz++];
}

Block *bklist;
Curor cur;

void init() {
	sz = 0;
	bklist = new Block;
	bklist->next = bklist->prev = NULL;
	bklist->len = maxn;
}

void loadStr(char *str) {
	bklist->next = newBlock();
	Block *nowbk = bklist->next;
	nowbk->prev = bklist;
	for(int i = 0; str[i] != 0; i++) {
		nowbk->data[nowbk->len++] = str[i];
		if(nowbk->len == maxn) {
			nowbk->next = newBlock();
			nowbk->next->prev = nowbk;
			nowbk = nowbk->next;
		}
	}
}

Curor move(Curor now, int k) {
	ggpos = k;
	now = Curor(bklist->next, 0);
	for(int i = 0; i < k; i++) {
		now.gpos++;
		if(now.gpos == now.bk->len) {
			now.bk = now.bk->next;
			now.gpos = 0;
		}
	}
	return now;
}


Curor prev(Curor now) {
	ggpos--;
	if(now.gpos == 0) return Curor(now.bk->prev, now.bk->prev->len - 1);
	return Curor(now.bk, now.gpos - 1);
}

Curor next(Curor now) {
	ggpos++;
	if(now.gpos == now.bk->len - 1) return Curor(now.bk->next, 0);
	return Curor(now.bk, now.gpos + 1);
}


//从光标处分裂
void split(Curor now) {
	if(now.gpos == 0) {
		//如果是块的开头就无需分裂
		return;
	}
	Block *newbk = newBlock();
	for(int i = now.gpos; i < now.bk->len; i++) {
		newbk->data[newbk->len++] = now.bk->data[i];
	}
	now.bk->len -= newbk->len;
	newbk->next = now.bk->next;
	newbk->prev = now.bk;
	if(now.bk->next != NULL ) now.bk->next->prev = newbk;
	now.bk->next = newbk;
}

//判断是否要合并,如果需要合并就合并
void maintain(Block *bk) {
	if(bk->next == NULL) return;
	if(bk->next->len + bk->len > maxn) return;
	for(int i = 0; i < bk->next->len; i++) {
		bk->data[bk->len++] = bk->next->data[i];
	}
	if(bk->next->next != NULL) bk->next->next->prev = bk;
	bk->next = bk->next->next;
	cur = move(cur, ggpos);
}

//在光标后插入字符串长度为n
void insert(Curor now, char *s, int n) {
	if(bklist->next == NULL) {
		loadStr(s);
		return;
	}
	//先从光标处分裂
	split(now);
	now = prev(now);
	Block *head = newBlock(), *nowbk = head;
	for(int i = 0; i < n; i++) {
		nowbk->data[nowbk->len++] = s[i];
		if(nowbk->len == maxn) {
			nowbk->next = newBlock();
			nowbk->next->prev = nowbk;
			nowbk = nowbk->next;
		}
	}
	if(now.bk->next != NULL)
		now.bk->next->prev = nowbk;
	nowbk->next = now.bk->next;
	head->prev = now.bk;
	now.bk->next = head;
	//如果能合并要合并
	maintain(now.bk);
	maintain(nowbk);
}

//删除光标后的n个字符
void deleten(Curor now, int n) {
	split(now); 
	now = prev(now);
	Curor nxt = next(now);
	for(int i = 0; i < n; i++) nxt = next(nxt);
	split(nxt);
	now.bk->next = nxt.bk;
	if(nxt.bk != NULL) nxt.bk->next->prev = now.bk->next;
	maintain(now.bk);
}

void get(Curor now, int n, char *buf) {
	for(int i = 0; i < n; i++) {
		*buf = now.bk->data[now.gpos];
		now = next(now);
		buf++;
	}
	*buf = 0;
}
void getStr(char *buf, int n) {
	char ch;
	while(n) {
		ch = getchar();
		if(ch != '\n') {
			*buf = ch;
			n--; buf++;
		}
	}
	*buf = 0;
}

char cmd[64];
char buf[4 * 1024 * 1024 + 10];
int n, q;

void display() {
	Block *p = bklist->next;
	while(p != NULL) {
		for(int i = 0;  i < p->len; i++) {
			fprintf(stderr, "%c", p->data[i]);
		}
		p = p->next;
	}
	fputs("\n", stderr);
}

int main() {

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	//初始化工作
	init();
	loadStr("@");
	cur = move(cur, 0);
	ggpos = 0;

	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		fprintf(stderr, "before op %d: ", i);
		fprintf(stderr, "now Curor is %c %d\n",cur.bk->data[cur.gpos], cur.gpos);
		display();
		scanf("%s", cmd);
		if(cmd[0] == 'M') {
			scanf("%d", &n);
			cur = move(cur, n);
		}
		if(cmd[0] == 'I') {
			scanf("%d", &n);
			getStr(buf, n);
			//fprintf(stderr, "get str %s\n", buf);
			insert(cur, buf, n);
		}
		if(cmd[0] == 'D') {
			scanf("%d", &n);
			deleten(cur, n);
		}
		if(cmd[0] == 'G') {
			scanf("%d", &n);
			get(cur, n, buf);
			puts(buf);
		}
		if(cmd[0] == 'P') cur = prev(cur);
		if(cmd[0] == 'N') cur = next(cur);
	}
	return 0;
}
