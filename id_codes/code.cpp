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

char line[60];
int l;

int
main()
{
	while(1)
	{
		scanf("%s", line);
		if(line[0] == '#') break;
		l = strlen(line);
		if(!next_permutation(line, line+l)) printf("No Successor\n");
		else printf("%s\n", line);
	}
	return 0;
}

