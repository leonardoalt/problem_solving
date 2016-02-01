#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

#define MAXN 100000
#define LSOne(S) (S & (-S))

int H[MAXN+MAXN+10];
int hasht[MAXN+10];
int tsize;

int
query(int x)
{
	int sum = 0;
	for(; x; x -= LSOne(x)) sum += H[x];
	return sum;
}

void
update(int x, int v, int n)
{
	for(; x <= n; x += LSOne(x)) H[x] += v;
}

int
main()
{
	int T, i, n, x, m, r, idx, f;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d", &m, &r);
		tsize = m + r;
		memset(H, 0, sizeof(H));
		memset(hasht, 0, sizeof(hasht));
		n = 1;
		for(i = r+1; i <= tsize; ++i)
		{
			update(i, 1, tsize);
			hasht[n++] = i;
		}
		f = r;
		while(r--)
		{
			scanf("%d", &n);
			idx = hasht[n];
			x = query(idx);
			update(idx, -1, tsize);
			hasht[n] = f;
			update(f, 1, tsize);
			--f;
			printf("%d", x - 1);
			if(r) printf(" ");
		}
		if(T) printf("\n");
	}

	return 0;
}


