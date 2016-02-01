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

int mat[9][9];

bool
ver_linha(int l)
{
	bool vec[10];
	int n;
	memset(vec, false, sizeof(vec));
	fori(9)
	{
		n = mat[l][i];
		if(vec[n]) return false;
		vec[n] = true;
	}
	return true;
}

bool
ver_col(int c)
{
	bool vec[10];
	int n;
	memset(vec, false, sizeof(vec));
	fori(9)
	{
		n = mat[i][c];
		if(vec[n]) return false;
		vec[n] = true;
	}
	return true;
}

bool
ver_quad(int l, int c)
{
	bool vec[10];
	int n;
	memset(vec, false, sizeof(vec));
	for(int i = l; i < l+3; ++i)
	{
		for(int j = c; j < c+3; ++j)
		{
			n = mat[i][j];
			if(vec[n]) return false;
			vec[n] = true;
		}
	}
}

int
main()
{
	int t, ca=0;
	scanf("%d", &t);
	while(t--)
	{
		fori(9) forj(9) scanf("%d", &mat[i][j]);
		printf("Instancia %d\n", ++ca);
		fori(9) if(!ver_linha(i)) goto err;
		fori(9) if(!ver_col(i)) goto err;
		if(!ver_quad(0, 0)) goto err;
		if(!ver_quad(3, 0)) goto err;
		if(!ver_quad(6, 0)) goto err;
		if(!ver_quad(0, 3)) goto err;
		if(!ver_quad(3, 3)) goto err;
		if(!ver_quad(6, 3)) goto err;
		if(!ver_quad(0, 6)) goto err;
		if(!ver_quad(3, 6)) goto err;
		if(!ver_quad(6, 6)) goto err;
		printf("SIM\n");
		goto out;
	err:
		printf("NAO\n");
	out:
		printf("\n");
	}
	return 0;
}

