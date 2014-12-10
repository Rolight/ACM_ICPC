#include <cstdio>
#include <queue>

using namespace std;

struct Item {
	int QNum, Period, Time;
	bool operator < (const Item &x) const {
		if(Time != x.Time) return Time > x.Time;
		return QNum > x.QNum;
	}
};

int main() {
	priority_queue<Item> pq;
	char s[25];
	while(scanf("%s",s), s[0] != '#') {
		Item item;
		scanf("%d%d", &item.QNum, &item.Period);
		item.Time = item.Period;
		pq.push(item);
	}
	int K; scanf("%d",&K);
	while(K--) {
		Item r = pq.top(); pq.pop();
		printf("%d\n",r.QNum);
		r.Time += r.Period;
		pq.push(r);
	}
	return 0;
}
