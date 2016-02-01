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

int vec[13];
int n;
vector<bool> bvec;

int
main()
{
	int c;
	bool first = true;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		if(!first) printf("\n");
		first = false;
		fori(n) scanf("%d", &vec[i]);
		bvec.assign(n, false);
		fill(bvec.begin(), bvec.begin() + 6, true);
		do
		{
			c = 0;
			fori(n)
			{
				if(!bvec[i]) continue;
				++c;
				if(c == 6)
				{
					printf("%d\n", vec[i]);
					break;
				}
				printf("%d ", vec[i]);
			}
		}
		while(prev_permutation(bvec.begin(), bvec.end()));
	}
	return 0;
}

