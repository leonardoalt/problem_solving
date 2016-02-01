#include <stdio.h>
#include <assert.h>

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)
#define fork(n) for(int k = 0; k < n; ++k)

int mat[3][3];
char let[3] = {'B', 'G', 'C'};
int ro[3] = {0, 2, 1};
int a, b, c, x, ans;
char ra, rb, rc;

void
func(int i, int j, int k)
{
	a = ro[i], b = ro[j], c = ro[k];
	ans = mat[0][b] + mat[0][c] + mat[1][a] + mat[1][c] + mat[2][a] + mat[2][b];
	if(ans < x)
	{
		x = ans;
		ra = let[a], rb = let[b], rc = let[c];
	}
}

int
main()
{
	while(1)
	{
		fori(3) forj(3) cin >> mat[i][j];
		if(cin.eof()) break;
		x = INT_MAX;
		fori(3)
		{
			forj(3)
			{
				if(j == i) continue;
				fork(3)
				{
					if(k == i || k == j) continue;
					func(i, j, k);
				}
			}
		}
		printf("%c%c%c %d\n", ra, rb, rc, x);
	}
	return 0;
}

