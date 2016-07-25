#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
void exc(char &a,char &b)
{
	char t = a;
	a = b;
	b = t;
}
int main()
{char a,b,c;
	while (cin >> a >> b >> c)
	{
		if (a > b) exc(a,b);
		if (b > c) exc(b,c);
		if (a > b) exc(a,b);
		printf("%c %c %c\n",a,b,c);	
	}
	return 0;
}
