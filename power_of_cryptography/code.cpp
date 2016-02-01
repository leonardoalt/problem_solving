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

int
main()
{
	double n, p, k;
	while(scanf("%lf %lf", &n, &p) != EOF)
	{
		k = exp(log(p)/n);
		printf("%.0lf\n", k);
	}
	return 0;
}

