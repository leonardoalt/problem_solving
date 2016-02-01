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

#define MAXS 50010
#define MAXP 5

int mat[MAXP][MAXS];

int
main()
{
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF)
	{
		memset(mat, 0, sizeof(mat));
		fori(m) forj(n)
		{
			scanf("%d", &mat[j][i]);
		}
		for(int i = 1; i < m; ++i)
			mat[0][i] += mat[0][i-1];
		for(int i = 1; i < n; ++i) forj(m)
		{
			if(j == 0)
				mat[i][0] += mat[i-1][0];
			else
			{
				if(mat[i][j-1] > mat[i-1][j]) mat[i][j] += mat[i][j-1];
				else mat[i][j] += mat[i-1][j];
			}
		}
		fori(m-1) printf("%d ", mat[n-1][i]);
		printf("%d\n", mat[n-1][m-1]);
	}
	return 0;
}

