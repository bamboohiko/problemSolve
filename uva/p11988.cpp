#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;
int next[100100];
int main()
{string s;
	while (cin >> s)
		{s = " " + s;
		int cur=0,last=0;
		memset(next,0,sizeof(next));
		for (int i = 1;i <= s.length(); i++)
			{if (s[i] == '[') cur = 0;
			if (s[i] == ']') cur = last;
			if (isalpha(s[i]))
				{next[i] = next[cur];
				next[cur] = i;
				if (cur == last) last = i;
				cur = i;
				}
			}
		for (int i = next[0]; ; i = next[i])
			{cout << s[i];
			if (i == last) break;
			}
		cout << endl;
		}
	return 0;
}
