#include <climits>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

#define MAXN 510

int mat[MAXN][MAXN];
int r, c, q, ii, is;

void
func()
{
	bool found;
	int ll = 0, lr = min(r, c)+1, ans = 0, m;
	while(ll < (lr - 1))
	{
		m = (ll + lr) / 2;
		found = false;
		fori(r-(m-1)) forj(c-(m-1))
		{
			int ci = mat[i][j], cs = mat[i+(m-1)][j+(m-1)];
			if(ci >= ii && cs <= is) { found = true; goto out; }
		}
	out:
		if(found)
		{
			if(m > ans) ans = m;
			ll = m;
		}
		else lr = m;
	}
	printf("%d\n", ans);
}

int
main()
{
	while(1)
	{
		scanf("%d %d", &r, &c);
		if(!r && !c) break;
		fori(r) forj(c) scanf("%d", &mat[i][j]);
		scanf("%d", &q);
		fori(q) { scanf("%d %d", &ii, &is); func(); }
		printf("-\n");
	}

	return 0;
}

