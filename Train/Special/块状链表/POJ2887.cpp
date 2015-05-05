#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 1e6 + 3000;
const int maxm = 1024;
char str[maxn];

//块状链表结构
struct Chunk {
	char data[maxm];
	int len, next, prev;
};

struct ChunkList {
	Chunk ck[maxn];
	int ckCnt, chCnt;
	void init() {
		ckCnt = chCnt = 0;
		//附加头结点
		ck[0].next = ck[0].prev = -1;
		ck[0].len = maxm - 1;
	}

	void loadStr(char *str) {
		int len = strlen(str), pos = 0, cpos = 0;
		while(pos < len) {
			int nxt = newChunk(-1, cpos);
			ck[cpos].next = nxt;
			cpos = nxt;
			for(int j = 1; pos < len && j < maxm; j++, pos++) {
				ck[cpos].data[j] = str[pos];
				ck[cpos].len++;
				chCnt++;
			}
		}
	}

	//新建块
	int newChunk(int next, int prev) {
		ckCnt++;
		ck[ckCnt].next = next;
		ck[ckCnt].prev = prev;
		ck[ckCnt].len = 0;
		return ckCnt;
	}

	//查找字符
	char query(int pos) {
		int i;
		for(i = ck[0].next; ~i && ck[i].len < pos; i = ck[i].next) {
			pos -= ck[i].len;
		}
		return ck[i].data[pos];
	}

	//分裂 
	void split(int cpos) {
		int nxt = newChunk(ck[cpos].next, cpos);
		ck[ck[cpos].next].prev = nxt;
		ck[cpos].next = nxt;
		for(int i = ck[cpos].len / 2 + 1, j = 1; i <= ck[cpos].len; i++, j++) {
			ck[nxt].data[j] = ck[cpos].data[i];
			ck[nxt].len++;
		}
		ck[cpos].len -= ck[nxt].len;
	}

	//插入字符
	void insert(char ch, int pos) {
		//直接特判在末尾插入的
		if(pos > chCnt) {
			int cpos = ck[0].next;
			while(ck[cpos].next != -1) cpos = ck[cpos].next;
			if(ck[cpos].len == maxm - 1) {
				int nxt = newChunk(-1, cpos);
				ck[cpos].next = nxt;
				ck[nxt].len = 1;
				ck[nxt].data[1] = ch;
			}
			else ck[cpos].data[++ck[cpos].len] = ch;
		}
		else {
			//寻找位置
			int cpos = ck[0].next;
			while(ck[cpos].len < pos) {
				pos -= ck[cpos].len;
				cpos = ck[cpos].next;
			}
			if(ck[cpos].len == maxm - 1) {
				//如果块满了要分裂
				split(cpos);
				if(pos > ck[cpos].len + 1) {
					pos -= ck[cpos].len;
					cpos = ck[cpos].next;
				}
			}
			for(int i = ck[cpos].len + 1; i > pos; i--) {
				ck[cpos].data[i] = ck[cpos].data[i - 1];
			}
			ck[cpos].data[pos] = ch;
			ck[cpos].len++;

		}
		chCnt++;
	}

	void display() {
		for(int i = ck[0].next; ~i; i = ck[i].next) {
			for(int j = 1; j <= ck[i].len; j++) {
				putchar(ck[i].data[j]);
			}
		}
		puts("");
	}
};

ChunkList cl;

int main() {
	scanf("%s", str);
	cl.init();
	cl.loadStr(str);
	char cmd, ch;
	int qpos, q;
	scanf("%d", &q);
	while(q--) {
		scanf(" %c", &cmd);
		if(cmd == 'Q') {
			scanf("%d", &qpos);
			printf("%c\n", cl.query(qpos));
		}
		else if(cmd == 'D') cl.display();
		else {
			scanf(" %c%d", &ch, &qpos);
			cl.insert(ch, qpos);
		}
	}
	return 0;
}
