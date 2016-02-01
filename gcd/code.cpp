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

#define MAXN 510

int mat[MAXN][MAXN];

int
gcd(int a, int b)
{
	if(a == 0 || b == 0) return 0;
	int t;
	while(b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int
main()
{
	int n, g;
	fori(MAXN) forj(MAXN) mat[i][j] = gcd(i, j);
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		g = 0;
		for(int i = 1; i < n; ++i) for(int j = i + 1; j <= n; ++j) g += gcd(i, j);
		printf("%d\n", g);
	}
	return 0;
}

