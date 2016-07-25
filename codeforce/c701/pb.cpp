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
bool vis[2][100100];
int main() {
    LL n,r = 0,c = 0;
    int m,x,y,fr = 0;
    scanf("%I64d%d",&n,&m);
    for (int i = 1;i <= m; i++) {
        scanf("%d%d",&x,&y);
        if (!vis[0][x]) {r++;vis[0][x] = true;}
        if (!vis[1][y]) {c++;vis[1][y] = true;}
        //cout << r << " " << c << endl;
        if (!fr) {
            printf("%I64d",(n-r-c)*n+r*c);
            fr = 1;
        } else printf(" %I64d",(n-r-c)*n+r*c);
    }
    printf("\n");
	return 0;
}
