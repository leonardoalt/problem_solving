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

#define MAXN 400000
#define MAXI 100000

int H[MAXN];
int A[MAXI];

void
init(int node, int b, int e)
{
	if(b == e)
	{
		H[node] = A[b-1];
		return;
	}
	int m = (b + e) / 2;
	init(node*2, b, m);
	init(node*2+1, m+1, e);
	H[node] = max(H[node*2], H[node*2+1]);
}

void
update(int node, int b, int e, int p, int v)
{
	if(p > e || p < b) return;
	if(b == e && b == p)
	{
		H[node] = v;
		return;
	}
	int m = (b + e) / 2;
	update(node*2, b, m, p, v);
	update(node*2+1, m+1, e, p, v);
	H[node] = max(H[node*2], H[node*2+1]);
}

int
query(int node, int b, int e, int i, int j)
{
	if(i > e || j < b) return INT_MIN;
	if(i >= b && j <= e) return H[node];
	int m = (b + e) / 2;
	int q0 = query(node*2, b, m, i, j);
	int q1 = query(node*2+1, m+1, e, i, j);
	return max(q0, q1);
}

int
main()
{
	int n, a, b, c, q;
	scanf("%d", &n);
	fori(n) scanf("%d", &A[i]);
	init(1, 1, n);
	scanf("%d", &q);
	fori(q)
	{
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0) update(1, 1, n, b, c);
		else if(a == 1) printf("%d\n", query(1, 1, n, b, c));
	}
	return 0;
}

