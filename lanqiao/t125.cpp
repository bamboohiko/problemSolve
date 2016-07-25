#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
int a[110][110];
int main() {
    int n,m;
    int x,y,k,d;
    char ch;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n; i++)
        for (int j = 0;j < m; j++)
            scanf("%d",&a[i][j]);
    scanf("%d%d%*c%c%d",&x,&y,&ch,&k);
    if (ch == 'U') d = 0;
    else if (ch == 'R') d = 1;
    else if (ch == 'D') d = 2;
    else d = 3;
    for (int i = 1;i <= k; i++) {
        if (a[x][y] == 1) d = (d+1)%4;
        else d = (d+3)%4;
        a[x][y] = 1-a[x][y];
        if (d == 0) x--;
        else if (d == 1) y++;
        else if (d == 2) x++;
        else y--;
    }
    printf("%d %d\n",x,y);
	return 0;
}

