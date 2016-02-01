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
	double dr, dn, a;
	while(scanf("%lf %lf", &dr, &dn) != EOF)
	{
		a = (dn/2) * sin((2*(2*acos(0)))/dn) * dr*dr;
		a = round(a * 1000) / 1000;
		printf("%.3lf\n", a);
	}
	return 0;
}

