#include <iostream>
#include <cstring>

using namespace std;

#define MAX 1002
#define LSOne(S) (S & (-S))

long long H[MAX][MAX];

void
create(int n1, int n2)
{
	for(int i = 0; i <= n1; ++i)
		memset(H[i], 0, (n2 + 1) * sizeof(long long));
}

long long
query2(int x, int y)
{
	long long sum = 0;
	for(; y; y -= LSOne(y)) sum += H[x][y];
	return sum;
}

long long
query(int x1, int y1, int x2, int y2)
{
	long long sum = 0;
	if(x1 != 1)
		return query(1, y1, x2, y2) - query(1, y1, x1-1, y2);
	for(; x2; x2 -= LSOne(x2))
	{
		sum += query2(x2, y2);
		if(y1 != 1) sum -= query2(x2, y1-1);
	}
	return sum;
}

void
update(int x, int y, int v, int n1, int n2)
{
	for(; x <= n1; x += LSOne(x))
		for(int y2 = y; y2 <= n2; y2 += LSOne(y2))
			H[x][y2] += v;
}

void
update_set(int x, int y, int v, int n1, int n2)
{
	int qt = query(x, y, x, y);
	update(x, y, -qt, n1, n2);
	update(x, y, v, n1, n2);
}

int
main()
{
	int x, y, a, b, c, d, i, j, n, q, e, f, g, h;
	long long p, r, qt;
	char co;

	while(1)
	{
		cin >> x >> y >> p;
		if(!x && !y && !p)
			break;

		create(x, y);

		cin >> q;
		while(q--)
		{
			cin >> co;
			if(co == 'A')
			{
				cin >> n >> a >> b;
				++a; ++b;
				update(a, b, n, x, y);
			}
			else //if(c == 'P')
			{
				cin >> a >> b >> c >> d;
				++a; ++b; ++c; ++d;
				e = min(a, c); g = max(a, c); f = min(b, d); h = max(b, d);
				qt = query(e, f, g, h);
				r = qt * p;
				cout << r << endl;
			}
		}
		cout << endl;
	}

	return 0;
}

