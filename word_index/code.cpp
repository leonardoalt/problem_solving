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

map<int, int> mapa;

int pots[5] = {1, 26, 676, 17576, 456976};

int
main()
{
	int a, b, c, d, e, acc;
	string s;
	a = 1;
	b = 27;
	c = 352;
	d = 2952;
	e = 17902;
	for(int i = 'a'; i <= 'z'; ++i)
	{
		mapa[i] = a++;
		for(int j = i + 1; j <= 'z'; ++j)
		{
			acc = i + j*26;
			mapa[acc] = b++;
			for(int k = j + 1; k <= 'z'; ++k)
			{
				acc = i + j*26 + k*pots[2];
				mapa[acc] = c++;
				for(int l = k + 1; l <= 'z'; ++l)
				{
					acc = i + j*26 + k*pots[2] + l*pots[3];
					mapa[acc] = d++;
					for(int m = l + 1; m <= 'z'; ++m)
					{
						acc = i + j *26 + k*pots[2] + l*pots[3] + m*pots[4];
						mapa[acc] = e++;
					}
				}
			}
		}
	}

	while(cin >> s)
	{
		acc = 0;
		fori(int(s.size())) acc += int(s[i]) * pots[i];
		if(mapa.count(acc)) printf("%d\n", mapa[acc]);
		else printf("0\n");
	}

	return 0;
}

