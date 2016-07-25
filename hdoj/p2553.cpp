#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool r[30],c1[30],c2[30];
int ans[30];
int n,sum;
void print()
{
	for (int i = 1;i < n; i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	sum++;
}
void dfs(int k)
{
	//cout << k << " " << n << endl;
	if (k > n) 
		{//cout << "!" << endl;
		//print();
		sum++;
		return;
		}
	for (int i = 1;i <= n; i++)
		if (!r[i] && !c1[k-i+n] && !c2[k+i])
			{//cout << k << " " << i << endl;
			ans[k] = i;
			r[i] = c1[k-i+n] = c2[k+i] = true;
			dfs(k+1);
			r[i] = c1[k-i+n] = c2[k+i] = false; 
			}
}
int main()
{
	while (scanf("%d",&n) != EOF && n)
		{
		sum = 0;
		dfs(1);
		printf("%d\n",sum);
		}
	return 0;
}
