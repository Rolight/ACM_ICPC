#include <iostream>
#include <queue>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

const int sigma_size = 27;
const int maxn = 8000;

struct TreeNode {
	int lson,rson,data,id;
	TreeNode(int lson = 0,int rson = 0,int data = -1,int id = 0):
		lson(lson),rson(rson),data(data),id(id) {}
	bool operator < (const TreeNode &x) const {
		return data > x.data;
	}
};

struct HaffumanTree {
	int cnt[sigma_size],sz,root;
	priority_queue<TreeNode> pq;
	TreeNode pool[maxn];
	string str;
	HaffumanTree(string ss):str(ss) {
		memset(cnt,0,sizeof(cnt));
		while(!pq.empty()) pq.pop();
		Construct();
		sz = 0;
	}
	void Construct() {
		int m = str.size();
		for(int i = 0;i < m;i++) {
			if(str[i] == '_') str[i] = 'Z' + 1;
			cnt[str[i] - 'A']++;
		}
		for(int i = 0;i < sigma_size;i++) {
			if(cnt[i]) {
				sz++;
				pool[sz] = TreeNode(0,0,cnt[i],sz);
				pq.push(pool[sz]);
			}
		}
		TreeBuild();
	}
	void TreeBuild() {
		while(pq.size() > 1) {
			TreeNode max1 = pq.top(); pq.pop();
			TreeNode max2 = pq.top(); pq.pop();
			TreeNode &new_node = pool[++sz];
			new_node.lson = max1.id;
			new_node.rson = max2.id;
			new_node.data = max1.data + max2.data;
			new_node.id = sz;
			pq.push(new_node);
		}
		root = pq.top().id;
	}
	int dfs(int now,int deep) {
		if(pool[now].lson + pool[now].rson == 0) {
			return deep * pool[now].data;
		}
		return dfs(pool[now].lson,deep + 1) + dfs(pool[now].rson,deep + 1);
	}
	int solve() {
		int ret = dfs(root,0);
		if(ret == 0) ret = pool[root].data;
		return ret;
	}
};

int main() {
	string buf;
	while(cin >> buf) {
		if(buf == "END") break;
		HaffumanTree hf(buf);
		int ori = buf.size() * 8,opt = hf.solve();
		cout << fixed << setprecision(1);
		cout << ori << " " << opt << " " << (double)ori / opt << endl;
	}
	return 0;
}


