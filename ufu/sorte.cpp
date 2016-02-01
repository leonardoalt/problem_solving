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
	int n, k, m, ca=0;
	double a, d;
	string s, b;
	while(scanf("%d", &n) != EOF)
	{
		a = INT_MAX;
		b = "";
		while(n--)
		{
			cin >> s >> k >> m;
			d = pow(double(k), double(m));
			if(d < a)
			{
				a = d;
				b = s;
			}
		}
		cout << "Caso " << ++ca << ": " << b << endl;
	}
	return 0;
}

