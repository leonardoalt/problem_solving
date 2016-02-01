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

#define MAXN 30000

char buf[MAXN+10];

int
main()
{
	int t, p, pin, lp, ca=0;
	bool inloop;
	char c;
	string input, prog;
	scanf("%d", &t);
	while(t--)
	{
		cin >> input >> prog;
		memset(buf, 0, sizeof(buf));
		p = pin = 0;
		inloop = false;
		printf("Instancia %d\n", ++ca);
		fori(int(prog.size()))
		{
			c = prog[i];
			if(c == '>') ++p;
			else if(c == '<') --p;
			else if(c == '+') ++buf[p];
			else if(c == '-') --buf[p];
			else if(c == '.') printf("%c", buf[p]);
			else if(c == ',')
			{
				if(pin < int(input.size()))
				{
					buf[p] = input[pin++];
				}
				else buf[p] = 0;
			}
			else if(c == '[')
			{
				if(buf[p] != 0)
				{
					inloop = true;
					lp = i;
				}
				else
				{
					while(prog[i] != ']') ++i;
				}
			}
			else if(c == ']')
			{
				if(buf[p] == 0)
				{
					inloop = false;
				}
				else
				{
					i = lp - 1;
				}
			}
			else if(c == '#')
			{
				fori(10) printf("%c", buf[i]);
			}
		}
		printf("\n\n");
	}
	return 0;
}

