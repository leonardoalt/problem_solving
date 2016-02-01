#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <climits>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

#define MAXC 1000
#define MAXG 100

int cut[MAXG];
int born[MAXG];
int visited[MAXC+10];

typedef pair<int, int> state;

int
main()
{
	int n, ans;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		fori(n) scanf("%d", &cut[i]);
		fori(n) scanf("%d", &born[i]);
		memset(visited, false, sizeof(visited));
		ans = -1;
		queue<state> q;
		q.push(state(0, 100));
		visited[100] = true;
		while(!q.empty())
		{
			state s = q.front(); q.pop();
			int d = s.first;
			int c = s.second;
			//cout << "\n\n\nD = " << d << " | C = " << c << endl;
			if(c == 0)
			{
				ans = d;
				break;
			}
			fori(n)
			{
				int g = cut[i];
				if(g > c) continue;
				int fc = c - g;
				//cout << "FC = " << fc << endl;
				if(fc == 0)
				{
					q.push(state(d + 1, 0));
					continue;
				}
				fc += born[i];
				//if(fc > 1000) goto err;
				if(fc > 1000) continue;
				//cout << "FC2 = " << fc << endl;
				if(!visited[fc])
				{
					//cout << "PUSH" << endl;
					visited[fc] = true;
					q.push(state(d + 1, fc));
				}
			}
		}
		err:
		if(ans == -1) printf("cavaleiro morreu\n");
		else printf("%d\n", ans);
	}
	return 0;
}

