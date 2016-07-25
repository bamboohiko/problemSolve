#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int act[4][2] = {0,1,1,0,0,-1,-1,0};
const char sav[4] = {'R','D','L','U'};
struct node{
	int x,y;
	string path;
};
queue<node> line;
int use[610][610],a[610][610],m,n;
bool check(int x,int y)
{
	if (use[x][y]) return false;
	if (x < 0 || x >= m || y < 0 || y >= n) return false;
	return true;
} 
int main()
{
		cin >> m >> n;
		int nx,ny;
		node s;
		scanf("%d%d%d%d",&s.x,&s.y,&nx,&ny); 
		memset(use,0,sizeof(use));
		use[s.x][s.y] = 1;s.path = "";
		line.push(s);
		for (int i = 0;i < m; i++)
			for (int j = 0;j < n; j++)
				scanf("%d",&a[i][j]);
		while (!line.empty())
			{node s = line.front();line.pop();
			//printf("*%d %d\n",s.x,s.y);
			if (s.x == nx && s.y == ny) 
				{cout << s.path.size() << endl;
				cout << s.path << endl;
				break;
				}
			for (int i = 0;i < 4; i++)
				if (!((1 << i)&a[s.x][s.y]))
					{//printf("%d %d %d\n",i,act[i][0],act[i][1]);
					node t;
					t.x = s.x + act[i][0];
					t.y = s.y + act[i][1];
					t.path = s.path + sav[i];
					if (check(t.x,t.y))
						{//printf("%d %d\n",t.x,t.y);
						line.push(t);
						use[t.x][t.y] = 1;
						}
					}
			}
	return 0;
}
