#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int vis[60][60];
int a[60][60];
int n,m,ans;
int check(int x,int y)
{
	//cout << x << " " << y << endl;
	if (((x >= 1) && (x <= n) && (y >= 1) && (y <= m) && !vis[x][y])) return 1;
	else return 0;
}
/*int bfs(int cou)
{int r=0,c=1,nx,ny;
	if ((!cou) || ((cou == 1) && (a[1][1] == 1))) return 0;
	memset(vis,0,sizeof(vis));
	line[0].x=1;line[0].y=1;
	line[0].t=0;line[0].c=cou-a[1][1];
	vis[1][1]=1;
	while (r<c) 
		{for (int i = 0;i < 4; i++)
			{nx=line[r].x+move[i][0];
			ny=line[r].y+move[i][1];
			if (check(nx,ny)) 
				{line[c].x=nx;
				 line[c].y=ny;
				 line[c].t=line[r].t+1;
				 line[c].c=line[r].c-a[nx][ny];
				 if (c <= 10) printf("%d %d %d %d\n",line[c].x,line[c].y,line[c].c,line[c].t);
				 if (!line[c].c) return (line[c].t+line[c].x+line[c].y-2);
				 vis[nx][ny]=1;
				 c++;				   
				}
			}
		r++;
		}
	return 0;
}*/
void dfs(int x,int y,int t,int c)
{int nx,ny;
	//cout << x << " " << y << " " << t << " "<< c << endl;
	if (c == 0) 
		{ans=min(ans,x+y+t-2);
		return;
		}
	for (int i = 0;i < 4; i++)
		{nx=x+move[i][0];
		 ny=y+move[i][1];
		 if (check(nx,ny))
		 	{vis[nx][ny]=1;
		 	//cout << nx << " " << ny << endl;
		 	dfs(nx,ny,t+1,c-a[nx][ny]);
		 	vis[nx][ny]=0;
		 	}
		}	
}
int main()
{freopen("test.in","r",stdin);
 freopen("test.out","w",stdout);
 int cou,x;
	while (cin >> n >> m)
		{memset(a,0,sizeof(a));
		memset(vis,0.,sizeof(vis));
		cou=0;
		for (int i = 1;i <= n; i++)
			for (int j = 1;j <= m; j++)
				{cin >> x;
				if (x > 0) cou+=(a[i][j]=1);
				}
		vis[1][1]=1;
		ans=3*n*m;
		dfs(1,1,0,cou-a[1][1]);
		cout << ans << endl; 
		}
	return 0;
}
