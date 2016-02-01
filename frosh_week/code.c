#include <stdio.h>
#include <assert.h>

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

#define MAXN 3

int vec[MAXN+10];
int aux[MAXN+10];
int ans;
int n;

void
merge(int l, int m, int r)
{
	int i, j;
	int t = (r - l) + 1;
	int p0 = l, p1 = m + 1;
	fori(t)
	{
		if(p0 > m) aux[i] = vec[p1++];
		else if(p1 > r || vec[p1] >= vec[p0]) aux[i] = vec[p0++];
		else //if(vec[p1] < vec[p0])
		{
			aux[i] = vec[p1];
			ans += (m + 1) - p0;
			++p1;
		}
	}
	//memcpy(&vec[l], aux, t * sizeof(int));
	for(i = 0, j = l; i < t; ++i, ++j) vec[j] = aux[i];
}

void
mergesort(int l, int r)
{
	if(l == r) return;
	int m = (l + r) / 2;
	mergesort(l, m);
	mergesort(m + 1, r);
	merge(l, m, r);
}

int some_int();

int
main()
{
	//while(scanf("%d", &n) != EOF)
	//{
		n = some_int();
		__CPROVER_assume(n >= 1);
		__CPROVER_assume(n <= MAXN);
		fori(n)	//scanf("%d", &vec[i]);
			vec[i] = some_int();
		ans = 0;
		mergesort(0, n-1);
		assert(ans <= 1000000000);
		printf("%d\n", ans);
	//}
	return 0;
}

