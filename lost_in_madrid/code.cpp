#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAXV 301

vector<int> adj[MAXV];
double mat[MAXV][MAXV];
double eqs[MAXV][MAXV];
double ans[MAXV];

void
gaussian_elimination(double a[MAXV][MAXV], double b[MAXV], int n)
{
	int i, j, k, l, maxi;
	double f, aux;

	for(i = 0; i < n; ++i)
	{
		maxi = i;
		for(l = i; l < n; ++l)
			if(fabs(a[l][i]) > fabs(a[maxi][i])) maxi = l;

		for(l = 0; l < n; ++l) swap(a[i][l], a[maxi][l]);
		aux = b[i], b[i] = b[maxi], b[maxi] = aux;
		for(k=i+1; k<n; ++k)
		{
			f = a[k][i] / a[i][i];
			for(j=i; j<n; ++j) a[k][j] -= a[i][j] * f;
			b[k] -= b[i] * f;
		}
	}

	for(i=n-1; i>= 0; --i)
	{
		b[i] = b[i] / a[i][i]; a[i][i] = 1.0;
		for(j=i-1; j >= 0; --j)
			b[j] -= a[j][i] * b[i], a[j][i] = 0.0;
	}
}

int
main()
{
	int n, a, b, j, m, ap, i, v, k, u, idx;
	bool app[MAXV];
	int appl[MAXV];
	
	while(1)
	{
		cin >> n;
		if(!n)
			break;
		
		ap = 0;
		memset(app, false, sizeof(app));
		for(i = 0; i <= 300; ++i)
			adj[i].clear();
		for(i = 0; i < n; ++i)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			if(a <= 290 && !app[a]) {app[a] = true; if(a == 0) idx = ap; appl[ap++] = a;}
			if(b <= 290 && !app[b]) {app[b] = true; if(b == 0) idx = ap; appl[ap++] = b;}
		}
	
		for(i = 0; i < ap; ++i)
			for(j = 0; j < ap; ++j)
			{
				mat[appl[i]][appl[j]] = eqs[i][j] = 0.0f;
				for(k = 291; k <= 300; ++k)
					mat[appl[i]][k] = 0.0f;
			}
		
		for(i = 0; i < ap; ++i)
		{
			v = appl[i];
			for(j = 0; j < adj[v].size(); ++j)
			{
				u = adj[v][j];
				mat[v][u] = 1.f / adj[v].size();
			}
		}

		for(i = 0; i < ap; ++i)
		{
			v = appl[i];
			ans[i] = mat[v][300] * -1;
			for(k = 0, j = 0; j < ap; ++k, ++j)
			{
				u = appl[j];
				if(j == i)
					eqs[i][k] = -1.0;
				else				
					eqs[i][k] = mat[v][u];
			}
		}

		gaussian_elimination(eqs, ans, ap);
		printf("%.3f", ans[idx]);
		cout << endl;
	}
	
	return 0;
}

