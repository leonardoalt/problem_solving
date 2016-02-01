#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
#define forx(n) for(int x = 0; x < n; ++x)

#define MAXN 1010

vector<int> adj[MAXN*MAXN];
bool visited[MAXN*MAXN];

vector<int> aut0[MAXN][2];
vector<int> aut1[MAXN][2];

int n1, n2, n3;
int si1, si2, si3, sf1, sf2, sf3;

void
inters()
{
	int s, t;

	n3 = n1 * n2;

	fori(n3) adj[i].clear();

	fori(n1)
		forj(n2)
		{
			s = i * n2 + j;
			forx(2)
				for(int y = 0; y < (int)aut0[i][x].size(); ++y)
					for(int z = 0; z < (int)aut1[j][x].size(); ++z)
					{
						t = aut0[i][x][y] * n2 + aut1[j][x][z];
						adj[s].push_back(t);
					}
		}
}

void
reada(int p, vector<int> aut[MAXN][2], int& n, int& si, int& sf)
{
	string w;
	int l, k, s;

	si = 0;
	n = 2;
	sf = 1;

	fori(p*40+2) { aut[i][0].clear(); aut[i][1].clear(); }

	fori(p)
	{
		cin >> w;

		l = (int)w.size();
		s = 0;
		forj(l)
		{
			if(j == 0)
			{
				if(j == l-1) k = sf;
				else k = n;
			}

			if(j == l-1)
			{
				aut[s][w[j] - '0'].push_back(sf);
				aut[sf][w[0]-'0'].push_back(k);
			}
			else
			{
				aut[s][w[j] - '0'].push_back(n);
				s = n++;
			}
		}
	}
}

int
main()
{
	bool ans;
	int u, v, s, c, t;
	int np1, np2;

	while(scanf("%d %d", &np1, &np2) != EOF)
	{
		reada(np1, aut0, n1, si1, sf1);
		reada(np2, aut1, n2, si2, sf2);
		si3 = 0;
		sf3 = sf1 * n2 + sf2;

		inters();

		ans = false;

		queue<int> q; q.push(si3);
		memset(visited, false, sizeof(visited));
		while(!q.empty())
		{
			u = q.front(); q.pop();
			if(u == sf3) { ans = true; break; }

			fori((int)adj[u].size())
			{
				v = adj[u][i];
				if(!visited[v])
				{
					visited[v] = true;
					q.push(v);
				}
			}
		}

		if(ans) printf("S\n");
		else printf("N\n");
	}

	return 0;
}
