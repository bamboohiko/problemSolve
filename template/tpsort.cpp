#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;
stack<int> s[30010];
int line[100010];
int vis[100010];
int tpsort(int v,int n)
{int r=0,c=1;
	line[0]=v;
	while (r < c) 
		{while (!s[line[r]].empty())
			{line[c++]=s[line[r]].top();
			s[line[r]].pop();
			}	
		sort(line+r+1,line+c);
		r++;
		}
	for (int i = 0;i < n; i++) cout << line[i] << " ";
	cout << line[n] << endl;
}
int main()
{freopen("tpsort.in","r",stdin);
 freopen("tpsort.out","w",stdout);
 int t,n,m,x,y;
 	cin >> t;
 	for (int j = 1;j <= t; j++ )  
 		{cin >> n >> m;
 		memset(vis,0,sizeof(vis));
 		for(int i = 1;i <= m; i++ )
		 	{cin >> x >> y;
		 	s[x].push(y);
		 	vis[y]=1;
		 	}
		for (int i = 1;i <= n; i++ )
			if (!vis[i]) tpsort(i,n-1);
 		}
	return 0;
}
