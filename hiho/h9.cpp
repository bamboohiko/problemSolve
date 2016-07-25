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
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int d = (1 << (1<<m))
    for (int i = 1;i <= n; i++)
        for (int j = 0;j < m; j++)
            for (int k = 0;k < (1<<(m<<1)); k++) {
                if (j) f[i][j][k] = f[i][j-1][k];
                else f[i][j][k] = f[i-1][m-1][(k<<m) + (1<<m)];
            }
	return 0;
}
