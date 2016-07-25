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
typedef long long LL;
const int n = 5842;
priority_queue<LL,vector<LL>,greater<LL> > q;
set<LL> dic;
LL a[6000];
int main()
{
	dic.clear();
	q.push(1);
	for (int i = 1;i <= n; i++)
	{
		do 
		{
			a[i] = q.top();
			q.pop();
		} 
		while (dic.count(a[i]));
		dic.insert(a[i]);
		q.push(a[i]*2);
		q.push(a[i]*3);
		q.push(a[i]*5);
		q.push(a[i]*7);
	}
	int k;
	while (scanf("%d",&k) != EOF && k)
	{
		string st = "th";
		if (k%10 == 1 && k%100 != 11) st = "st";
		if (k%10 == 2 && k%100 != 12) st = "nd";
		if (k%10 == 3 && k%100 != 13) st = "rd";
		printf("The %d",k);
		cout << st;
		printf(" humble number is %d.\n",a[k]);
	}
	return 0;
}
