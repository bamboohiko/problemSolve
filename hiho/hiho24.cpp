#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = 1 << 28;
int edge[110][110];
int main()
{int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n; i++)
		for (int j = 1;j <= n; j++)
			{edge[i][j] = INF;
			if (i == j) edge[i][j] = 0;
			}
	for (int i = 1;i <= m; i++)
		{int from,to,dist;
		scanf("%d%d%d",&from,&to,&dist);
		edge[from][to] = min(edge[from][to],dist);
		edge[to][from] = min(edge[to][from],dist);
		}
	for (int k = 1;k <= n; k++)
		for (int i = 1;i <= n; i++)
			for (int j = 1;j <= n; j++)
				edge[i][j] = min(edge[i][j],edge[i][k]+edge[k][j]);
	for (int i = 1;i <= n; i++)
		{for (int j = 1;j < n; j++)
			printf("%d ",edge[i][j]);
		printf("%d\n",edge[i][n]);
		}
	return 0;
}
