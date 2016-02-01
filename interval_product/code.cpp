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

#define MAXN 400000 //size of the tree (nlogn)
#define MAXI 100000 //size of the array (as the problem says)

int H[MAXN]; //seg tree
int A[MAXI]; //original array

inline int
signal(int n)
{
	if(n > 0) return 1;
	if(n == 0) return 0;
	return -1;
}

void
init(int node, int b, int e)
{
	if(b == e) //if b==e, it means this node is a leaf (interval [i,i])
	{
		H[node] = signal(A[b-1]); //then just copy from the array
		return;
	}
	int m = (b + e) / 2; //if this is an internal node, simply compute the operation that the problem requires after recursively computing the children's values (this will eventually reach the leaves, which are actually computed first)
	init(node*2, b, m); 
	init(node*2+1, m+1, e);
	H[node] = H[node*2] * H[node*2+1]; //here it's guaranteed that the children have their values computed already
}

void
update(int node, int b, int e, int p, int v)
{
	if(p > e || p < b) return; //this node has nothing to do with the requested interval
	if(b == e && b == p) //leave p, interval [p,p]
	{
		H[node] = signal(v); //update the reail value
		return;
	}
	int m = (b + e) / 2;
	update(node*2, b, m, p, v);
	update(node*2+1, m+1, e, p, v);
	H[node] = H[node*2] * H[node*2+1]; //same idea as init. Compute the children first, then update the inner node (interval [b,e]) with the new value (corresponding to the problem)
}

int
query(int node, int b, int e, int i, int j)
{
	if(i > e || j < b) return 1; //this node has nothing to do with the requested interval, so return the identity of the current operation
	if(b >= i && e <= j) return H[node]; //this node is a subinterval of the requested interval, so we use it
	int m = (b + e) / 2;
	int q0 = query(node*2, b, m, i, j);
	int q1 = query(node*2+1, m+1, e, i, j);
	return q0*q1; //merge the results of the children
}

int
main()
{
	int n, b, c, q;
	string a;
	while(scanf("%d %d", &n, &q) != EOF)
	{
		fori(n) scanf("%d", &A[i]);
		init(1, 1, n);
		fori(q)
		{
			cin >> a >> b >> c;
			if(a[0] == 'C') update(1, 1, n, b, c);
			else if(a[0] == 'P')
			{
				int r = query(1, 1, n, b, c);
				char lala = (r == 1) ? '+' : ((r == 0) ? '0' : '-');
				printf("%c", lala);
			}
		}
		printf("\n");
	}
	return 0;
}

