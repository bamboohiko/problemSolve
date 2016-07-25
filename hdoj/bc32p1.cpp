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
struct data{
	int num,dif,sec;
};
data a[110];
bool cmp(data a,data b)
{
	if (a.dif != b.dif) return a.dif < b.dif;
	if (a.sec != b.sec) return a.sec < b.sec;
	return a.num < b.num;
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 0;i < n; i++)
		{
			a[i].num = i;
			scanf("%d%d",&a[i].dif,&a[i].sec);
			a[i].dif = a[i].sec - a[i].dif;
		}
		sort(a,a+n,cmp);
		printf("%d",a[0].num);
		for (int i = 1;i < n; i++)
			printf(" %d",a[i].num);
		printf("\n");
	}
	return 0;
}
