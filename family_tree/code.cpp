#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

int
func(int n)
{
	if(n == 0) return 1;
	return 2 << (n - 1);
}

int
main()
{
	int t, n, a, b, to, nb, fb;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &a, &b);
		if(a > b) swap(a, b);

		to = func(n) - 1;
		nb = log(b) / log(2) + 1;
		fb = func((n - nb) + 1) - 2;
		printf("%d\n", to - fb);
	}

	return 0;
}

