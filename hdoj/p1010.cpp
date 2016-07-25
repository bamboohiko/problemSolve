#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int act[4][2] = {0,1,0,-1,1,0,-1,0};
int use[10][10],n,m,t,nx,ny;
bool check(int x,int y,int k)
{
	if (use[x][y]) return false;
	if (x < 1 || x > n || y < 1 || y > m) return false;
	//if (abs(x - nx) + abs(y - ny) > t-k) return false;
	return true;
}
bool dfs(int k,int x,int y)
{int kx,ky;
	//printf("%d %d %d\n",k,x,y);
	if (k == t)
		if (x == nx && y == ny) return true;
		else return false;
	int dis = (t - k) - abs(x - nx) + abs(y - ny);
	if (dis < 0 || dis%2) return false;
	for (int i = 0;i < 4; i++)
		if (check(kx = x+act[i][0],ky = y+act[i][1],k+1))
			{
			use[kx][ky] = 1;
			if (dfs(k+1,kx,ky)) return true;
			use[kx][ky] = 0;
			}
	return false;
}
int main()
{
	while (cin >> n >> m >> t && (n || m || t))
		{if (!(n && m)) continue;
		int x,y;char ch;
		memset(use,0,sizeof(use));
		for (int i = 1;i <= n; i++)
			{
			for (int j = 1;j <= m; j++)
				{cin >> ch;
				if (ch == 'S') {x = i;y = j;}
				if (ch == 'D') {nx = i;ny = j;}
				if (ch == 'X' || ch == 'x') use[i][j] = 1;
				}
			}
		use[x][y] = 1;
		if (dfs(0,x,y)) printf("YES\n");
		else printf("NO\n");
		}
	return 0;
}
