#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <climits>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

#define MAXK 1100000

int deg[MAXK];

int
main()
{
	int k, x;
	while(1)
	{
		scanf("%d", &k);
		if(!k) break;
		memset(deg, 0, k*sizeof(int));
		fori(k)
		{
			scanf("%d", &x);
			--x;
			++deg[x];
		}
		fori(k+1) printf("%d ", deg[i]+1);
		printf("%d\n", deg[k+1]+1);
	}
	return 0;
}

