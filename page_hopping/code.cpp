#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <climits>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
#define fork(n) for(int k = 0; k < n; ++k)

#define MAXN 110
#define INF 1000000000

int mat[MAXN][MAXN];
vector<int> apps;
bool app[MAXN];

void
fw()
{
	fork(MAXN)
	fori(MAXN)
	forj(MAXN)
	if((mat[i][k] + mat[k][j]) < mat[i][j]) mat[i][j] = mat[i][k] + mat[k][j];
}

void
ins(int a)
{
	if(!app[a])
	{
		app[a] = true;
		apps.push_back(a);
	}
}

int
main()
{
	int a, b, s, c, ca=0;
	double r;
	while(1)
	{
		scanf("%d %d", &a, &b);
		if(a == 0 && b == 0) break;

		--a; --b;
		fori(MAXN) forj(MAXN) mat[i][j] = INF;
		apps.clear();
		memset(app, false, sizeof(app));
		mat[a][b] = 1;
		ins(a);
		ins(b);
		while(1)
		{
			scanf("%d %d", &a, &b);
			if(a == 0 && b == 0) break;
			--a; --b;
			ins(a); ins(b);
			mat[a][b] = 1;
		}
		fw();
		s = 0;
		c = 0;
		fori(int(apps.size()))
		{
		a = apps[i];
		forj(int(apps.size()))
		{
			if(i == j) continue;
			b = apps[j];
			s += mat[a][b];
			++c;
		}
		}
		r = s / double(c);
		printf("Case %d: average length between pages = %.3lf clicks\n", ++ca, r);
	}
	return 0;
}

