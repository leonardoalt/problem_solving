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

#define MAXC 110
#define MAXP 10

int probs[MAXC];
bool acc[MAXC][MAXP];
int tries[MAXC][MAXP];
int penal[MAXC];
int app[MAXC];
bool isapp[MAXC];
int n;
vector<int> rank;

bool
func(int a, int b)
{
	if(probs[a] > probs[b]) return true;
	if(probs[a] < probs[b]) return false;
	if(penal[a] < penal[b]) return true;
	if(penal[a] > penal[b]) return false;
	return a < b;
}

int
main()
{
	int t, prob, time, id;
	string line;
	char op;
	scanf("%d", &t);
	getline(cin, line);
	getline(cin, line);
	while(t--)
	{
		rank.clear();
		n = 0;
		memset(tries, 0, sizeof(tries));
		memset(probs, 0, sizeof(probs));
		memset(acc, false, sizeof(acc));
		memset(penal, 0, sizeof(penal));
		memset(isapp, false, sizeof(isapp));
		while(1)
		{
			getline(cin, line);
			if(line == "") break;
			stringstream ss(line);
			ss >> id >> prob >> time >> op;
			if(!isapp[id])
			{
				isapp[id] = true;
				app[n++] = id;
				rank.push_back(id);
			}
			if(op == 'R' || op == 'U' || op == 'E') continue;
			if(acc[id][prob]) continue;
			if(op == 'I')
			{
				++tries[id][prob];
			}
			else if(op == 'C')
			{
				++probs[id];
				acc[id][prob] = true;
				penal[id] += time + 20 * tries[id][prob];
			}
		}
		sort(rank.begin(), rank.end(), func);
		fori(n)
		{
			id = rank[i];
			printf("%d %d %d\n", id, probs[id], penal[id]);
		}
		if(t) printf("\n");
	}
	return 0;
}
