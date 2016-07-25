#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int edge[1010][1010];
bool acc[1010][1010];
bool vis[1010];
void build(int a,int b)
{
	acc[a][b]=true;
	cin >> edge[a][b];
}
int main()
{int n,m,t,k,a,b,v,rec;
	while (cin >> n >> m) 
		{cin >> t >> k;
		memset(acc,0,sizeof(acc));
		memset(vis,0,sizeof(vis));
		for (int i = 1; i <= m;i++ )
			{cin >> a >> b;
			 build(a,b);
			}
		vis[t]=true;
		 for (int i = 2;i <= n;i++ )
		 	{v=t;
			 rec=INT_MAX;
			 for (int j = 1;j <= n;j++ )
		 		if ((!vis[j]) && (acc[i][j]) && (edge[i][j]<rec))
		 			{rec=edge[i][j];
					 v=j;
		 			}
		 	 vis[v]=1;
			 for (int j = 1;j <= n;j++ )
			 	if ((!vis[j]) && (acc[i][v]) && (acc[v][j])) 
			 		if (!(acc[i][j]))	
					 	{acc[i][j]=true;
					 	edge[i][j]=edge[i][v]+edge[v][j];
			 			}
			 		else edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
		 	}
		cout << edge[t][k] << endl;
		}
	return 0;
}
