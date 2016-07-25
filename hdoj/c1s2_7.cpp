#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
map<char,int> gpa;
int main()
{
	gpa['A'] = 4;gpa['B'] = 3;gpa['C'] = 2;gpa['D'] = 1;gpa['F'] = 0;
	string st;
	while (getline(cin,st))
	{
		double ans = 0;
		int sum = 0,rec = 1;
		for (int i = 0;i < st.size(); i++)
		{
			if (st[i] == ' ') continue;
			if (!gpa.count(st[i])) 
			{
				rec = 0;
				break;
			}
			ans = ans + gpa[st[i]];
			sum++;
		}
		if (rec) 
		{
			printf("%.2lf\n",ans/sum);
		}
		else 
		{
			printf("Unknown letter grade in input\n");
		}
	}
	return 0;
}
	
