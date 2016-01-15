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
const int move[4][2] = {1,0,-1,0,0,1,0,-1};
struct data {
	int x,y;
};
data from,to;
int vis[510][510],n,m,sum = 0;
char G[510][510];
bool check(int x,int y) {
	if (x == to.x && y == to.y) return true;
	if (x < 1 || x > n || y < 1 || y > m) return false;
	if (G[x][y] != '.') return false;
	return true;
}
bool bfs() {
	queue<data> Q;
	data d = from;
	Q.push(d);
	while (!Q.empty()) {
		data s = Q.front();Q.pop();
		//cout << s.x << " " << s.y << endl;
		for (int i = 0;i < 4; i++) {
			data t;
			t.x = s.x + move[i][0];
			t.y = s.y + move[i][1];
			//cout << t.x << " " << t.y << " " << G[t.x][t.y] << endl;
			if (check(t.x,t.y) && !vis[t.x][t.y]) {
				vis[t.x][t.y] = 1;
				if (t.x == to.x && t.y == to.y) return sum > 0;
				Q.push(t);
				//cout << t.x << " " << t.y << endl;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	//cout << n << " " << m << endl;
	for (int i = 1;i <= n; i++) {
		scanf("%*c");
		for (int j = 1;j <= m; j++)
			scanf("%c",&G[i][j]);
	}
	scanf("%d%d",&from.x,&from.y);
	scanf("%d%d",&to.x,&to.y);
	if (G[to.x][to.y] == 'X') sum = 1;
	else {
	    sum = -1;
        for (int i = 0;i < 4; i++) {
            if (G[to.x + move[i][0]][to.y + move[i][1]] == '.') sum++;
            if (to.x + move[i][0] == from.x && to.y + move[i][1] == from.y && G[from.x][from.y] == 'X') sum++;
        }
	}
	cout << sum << endl;
    if (bfs()) printf("YES\n");
	else printf("NO\n");
	return 0;
}
