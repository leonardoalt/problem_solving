#include <cfloat>
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

typedef pair<double, int> par;

par vec[1010];

int
main()
{
	int t, n, a, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		fori(n)
		{
			scanf("%d %d", &a, &b);
			vec[i].first = 1 / ( double(b)/a );
			vec[i].second = i + 1;
		}
		sort(vec, vec + n);
		printf("%d", vec[0].second);
		fori(n-1) printf(" %d", vec[i+1].second);
		printf("\n");
		if(t) printf("\n");
	}
	return 0;
}

