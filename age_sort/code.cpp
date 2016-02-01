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

#define MAXN 2000010

int vec[MAXN];

int
main()
{
	int n;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		fori(n) scanf("%d", &vec[i]);
		sort(vec, vec+n);
		printf("%d", vec[0]);
		fori(n-1) printf(" %d", vec[i+1]);
		printf("\n");
	}
	return 0;
}

