#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct point{
	int x,y,t,rt;
	point(int x=0,int y=0,int t=0,int rt=0):x(x),y(y),t(t),rt(rt) {}
};
const int move[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 
int lab[20][20];
int vis[20][20];
int n,m;
bool can(int x,int y,int rt)
{
	if ((x < 1) || (x > n) || (y < 1) || (y > m)) return false;
	if (lab[x][y] == 0) return false;
	if ((vis[x][y] != 0) && (rt <= vis[x][y])) return false;
	//cout << x << " " << y << endl;
	return true;
}
int main()
{int t; 
	cin >> t;
	while (t--)
		{int lx,ly,ans=-1;
			cin >> n >> m;
			queue<point> line;
			memset(lab,0,sizeof(lab));
			memset(vis,0,sizeof(vis));
			for (int i = 1;i <= n; i++)
				for (int j = 1;j <= m; j++)
					{cin >> lab[i][j];
					if (lab[i][j] == 2) 
						{point p(i,j,0,6); 
						vis[i][j]=7;
						line.push(p);
						}
					if (lab[i][j] == 3)
						{lx = i; ly = j;
						}
					}
			while (!line.empty())
				{point p=line.front();
				//printf("%d %d %d %d\n",p.x,p.y,p.t,p.rt);
				 line.pop();
					if (p.rt == 1) continue;
					if ((p.x == lx) && (p.y == ly)) 
						{ans = p.t;
						break;
						}
					for (int i = 0;i < 4; i++)
						{int nx = p.x+move[i][0];
						 int ny = p.y+move[i][1];
						if (can(nx,ny,p.rt)) 
							{vis[nx][ny]=p.rt;
							point np(nx,ny,p.t+1,p.rt-1);
							if (lab[nx][ny] == 4) np.rt=6;
							line.push(np);
							}
						}
				}
			cout << ans << endl;
		}
	return 0;
}
