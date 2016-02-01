#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define forid(n) for(int i=0;i<n;++i)
#define forjd(n) for(int j=0;j<n;++j)

#define MAXV 110
#define INF 1000000000

int mat[MAXV][MAXV];
int alt[MAXV][MAXV];

void
fw(int n)
{
	forid(n) forjd(n)
	for(int k = 0; k < n; ++k)
	{
		if(mat[i][j] > (mat[i][k] + mat[k][j]))
		{
			mat[i][j] = mat[i][k] + mat[k][j];

		}
			if(abs(alt[i][j]) < abs(alt[i][k])) alt[i][j] = alt[i][k];
			if(abs(alt[i][j]) < abs(alt[k][j])) alt[i][j] = alt[k][j];
	}
}

int
main()
{
	int n, m, a, b, c, d, ca=0;
	bool first = true;

	while(1)
	{
		cin >> n >> m;
		if(!n && !m) break;

		if(!first) printf("\n");
		first = false;

		forid(n)
		{
			forjd(n) mat[i][j] = INF;
			mat[i][i] = 0;
		}

		forid(m)
		{
			scanf("%d %d %d", &a, &b, &c);
			--a; --b;
			mat[a][b] = mat[b][a] = 1;
			alt[a][b] = alt[b][a] = c;
		}

		fw(n);

		printf("Instancia %d\n", ++ca);
		scanf("%d", &c);
		forid(c)
		{
			scanf("%d %d", &a, &b);
			--a; --b;
			d = 0;
			if(a != b) d = alt[a][b];
			printf("%d\n", d);
		}
	}

	return 0;
}

