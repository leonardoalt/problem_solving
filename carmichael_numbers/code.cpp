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

int vec[15] = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};

int
main()
{
	int n;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		if(binary_search(vec, vec+15, n)) printf("The number %d is a Carmichael number.\n", n);
		else printf("%d is normal.\n", n);
	}
	return 0;
}

