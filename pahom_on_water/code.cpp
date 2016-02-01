#include <queue>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

#define MAXN 610
#define INF 1000000000

struct point
{
	point() { x = y = r = 0; }
	point(int a, int b, int c) { x = a; y = b; r = c; }
	int x, y, r, f;
};

typedef vector<int> vi;

vi adj[MAXN];
int mat[MAXN][MAXN];
point points[MAXN];
int mf, f;
vi p;
int S, T;

void
augment(int v, int minedge)
{
	if(v == S) { f = minedge; return; }
	if(p[v] != -1)
	{
		augment(p[v], min(minedge, mat[p[v]][v]));
		mat[p[v]][v] -= f; mat[v][p[v]] += f;
	}
}

bool
inters(int a, int b)
{
	double d = hypot(points[a].x - points[b].x, points[a].y - points[b].y);
	return d < (points[a].r + points[b].r);
}

int
main()
{
	int is, t, n, a, b;
	double fd;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		fori(n*2) adj[i].clear();
		memset(mat, 0, sizeof(mat));
		fori(n)
		{
			scanf("%lf %d %d %d", &fd, &points[i].x, &points[i].y, &points[i].r);
			points[i].f = int(fd * 1000.0);
			if(points[i].f == 400000) S = i;
			else if(points[i].f == 789000) T = i;
			else
			{
				is = i + n;
				adj[i].push_back(is);
				adj[is].push_back(i);
				mat[i][is] = 1;
			}
		}

		fori(n)
		for(int j = i + 1; j < n; ++j)
		{
			if(i == j) continue;
			if(points[i].f == points[j].f) continue;
			if(inters(i, j))
			{
				a = i;
				b = j;
				if(points[a].f > points[b].f) swap(a, b);
				if(a != S && a != T) a += n;
				adj[a].push_back(b);
				adj[b].push_back(a);
				mat[a][b] = 1;
			}
		}

		n *= 2;
		mf = 0;
		while(1)
		{
			f = 0;
			vi dist(n, INF); dist[S] = 0;
			queue<int> q; q.push(S);
			p.assign(n, -1);
			while(!q.empty())
			{
				int u = q.front(); q.pop();
				if(u == T) break;
				forj((int)adj[u].size())
				{
					int v = adj[u][j];
					if(mat[u][v] > 0 && dist[v] == INF)
					{
						dist[v] = dist[u] + 1, q.push(v), p[v] = u;
					}
				}
			}
			augment(T, INF);
			if(f == 0) break;
			mf += f;
		}

		if(mf >= 2) printf("Game is VALID\n");
		else printf("Game is NOT VALID\n");
	}

	return 0;
}
