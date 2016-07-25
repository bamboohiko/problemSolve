#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10][10],use[10][10];
bool check(int x,int y)
{
	if (x < 1 || x > 4 || y < 1 || y > 4) return false;
	return true;
}
void move(int& x,int& y,int dx,int dy)
{
	while (check(x+dx,y+dy) && !a[x+dx][y+dy])
		{a[x+dx][y+dy] = a[x][y];
		a[x][y] = 0;
		x += dx;y += dy;
		}
}
void up()
{int x,y,dx = -1,dy = 0;
	for (int j = 1;j <= 4; j++)
		for (int i = 2;i <= 4; i++)
			{x = i;y = j;
			if (a[x][y]) move(x,y,dx,dy);
		    if (x > 1 && !use[x+dx][y+dy] && a[x][y] == a[x+dx][y+dy]) 
				{a[x+dx][y+dy] *= 2;a[x][y] = 0;
				 use[x+dx][y+dy] = 1;
				}	
			}
}
void down()
{int x,y,dx = 1,dy = 0;
	for (int j = 1;j <= 4; j++)
		for (int i = 3;i >= 1; i--)
			{x = i;y = j;
			if (a[x][y]) move(x,y,dx,dy);
		    if (x < 4 && !use[x+dx][y+dy] && a[x][y] == a[x+dx][y+dy]) 
				{a[x+dx][y+dy] *= 2;a[x][y] = 0;
				 use[x+dx][y+dy] = 1;
				}	
			}
}
void left()
{int x,y,dx = 0,dy = -1;
	for (int i = 1;i <= 4; i++)
		for (int j = 2;j <= 4; j++)
			{x = i;y = j;
			if (a[x][y]) move(x,y,dx,dy);
		    if (y > 1 && !use[x+dx][y+dy] && a[x][y] == a[x+dx][y+dy]) 
				{a[x+dx][y+dy] *= 2;a[x][y] = 0;
				 use[x+dx][y+dy] = 1;
				}	
			}
}
void right()
{int x,y,dx = 0,dy = 1;
	for (int i = 1;i <= 4; i++)
		for (int j = 3;j >= 1; j--)
			{x = i;y = j;
			if (a[x][y]) move(x,y,dx,dy);
		    if (y < 4 && !use[x+dx][y+dy] && a[x][y] == a[x+dx][y+dy]) 
				{a[x+dx][y+dy] *= 2;a[x][y] = 0;
				 use[x+dx][y+dy] = 1;
				}	
			}
}
int main()
{
	while (cin >> a[1][1])
		{string st;
		for (int i = 1;i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				if (i != 1 || j != 1) cin >> a[i][j];
		cin >> st;
		for (int i = 0;i < st.size(); i++)
			{memset(use,0,sizeof(use));
			 if (st[i] == 'U') up();
			 if (st[i] == 'D') down();
			 if (st[i] == 'L') left();
			 if (st[i] == 'R') right();
			}
		for (int i = 1;i <= 4; i++)
			{for (int j = 1;j < 4; j++)
				printf("%5d",a[i][j]);
			printf("%5d\n",a[i][4]);
			}
		printf("\n");
		}
	return 0;
}
