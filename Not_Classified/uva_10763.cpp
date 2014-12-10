#include <iostream>
#include <set>

using namespace std;

struct couple
{
	unsigned int a,b;
	couple(unsigned int from,unsigned int to):a(from),b(to) {
	}
};

bool operator< (couple a,couple b)
{
	if(a.a != b.a) return (a.a < b.a);
	else return (a.b < b.b);
}

multiset<couple> c;
unsigned int count = 0;

int main()
{
	int n;
	while((cin >> n) && n)
	{
		unsigned int from,to;
		c.clear();
		for(int i = 0;i < n;i++)
		{
			cin >> from >> to;
			couple temp(from,to);
			couple retemp(to,from);
			if(c.count(retemp) != 0)
				c.erase(c.find(retemp));
			else c.insert(temp);
		}
		if(c.size() == 0)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
