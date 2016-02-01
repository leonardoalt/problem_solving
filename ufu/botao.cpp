#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <sstream>
#include <map>
#include <set>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

typedef vector<int> vi;
typedef pair<int, int> point;
typedef pair<int, int> ii;
vi pset;

void
initSet(int n)
{
	pset.assign(n, 0);
	for(int i = 0; i < n; ++i) pset[i] = i;
}

int
findSet(int i)
{
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}

bool
isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}

void
unionSet(int i, int j)
{
	pset[findSet(i)] = findSet(j);
}

int
main()
{
	int N, E, n, x, y;
	char op;
	while(scanf("%d", &n) != EOF)
	{
		N = E = 0;
		vector<point> vec;
		while(n--)
		{
			cin >> op >> x >> y;
			if(op == 'R') continue;
			vec.push_back(point(x, y));
			++N;
		}
		vector< pair<double, ii> > elist;
		fori(int(vec.size())) forj(int(vec.size()))
		{
			if(i == j) continue;
			++E;
			elist.push_back(make_pair(hypot(double(vec[i].first - vec[j].first), double(vec[i].second - vec[j].second)), ii(i, j)));
		}

		sort(elist.begin(), elist.end());

		double mst_cost = 0; initSet(N);
		fori(E)
		{
			pair<double, ii> f = elist[i];
			if(!isSameSet(f.second.first, f.second.second))
			{
				mst_cost += f.first;
				unionSet(f.second.first, f.second.second);
			}
		}

		printf("%.4lf\n", mst_cost);
	}
	return 0;
}

