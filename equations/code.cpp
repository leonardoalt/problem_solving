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
#include <stack>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

char ans[100];
int p;
stack<char> st;

int
prec(char a, char b)
{
	if((a == '*' || a == '/') && (b == '+' || b == '-')) return 1;
	if((a == '*' || a == '/') && (b == '*' || b == '/')) return 0;
	if((a == '+' || a == '-') && (b == '+' || b == '-')) return 0;
	return -1;
}

int
main()
{
	int t, p;
	char c;
	string line;
	scanf("%d", &t);
	getline(cin, line);
	getline(cin, line);
	while(t--)
	{
		p = 0;
		while(1)
		{
			getline(cin, line);
			if(line == "") break;
			c = line[0];
			if(c >= '0' && c <= '9') ans[p++] = c;
			else if(c == '(') st.push(c);
			else if(c == ')')
			{
				while(!st.empty() && st.top() != '(')
				{
					ans[p++] = st.top();
					st.pop();
				}
				st.pop();
			}
			else if(c == '*' || c == '/' || c == '-' || c == '+')
			{
				if(st.empty()) st.push(c);
				else
				{
					while(!st.empty() && prec(st.top(), c) >= 0)
					{
						ans[p++] = st.top();
						st.pop();
					}
					st.push(c);
				}
			}
		}
		while(!st.empty()) { ans[p++] = st.top(); st.pop(); }
		fori(p) printf("%c", ans[i]);
		printf("\n");
		if(t) printf("\n");
	}
	return 0;
}

