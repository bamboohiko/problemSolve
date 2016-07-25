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
const int mov[4][2] = {0,1,0,-1,1,0,-1,0};
char a[200100];
int vis[200100],d[200100];
queue<int> Q;
int main() {
    int n,m,t;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n; i++) {
        scanf("%s",a+i*m);
        for (int j = 0;j < m; j++) {
            if (a[i*m+j] == '1') {Q.push(i*m+j);vis[i*m+j] = 1;}
            if (a[i*m+j] == '2') {t = i*m+j;}
        }
    }
    int ok = 0;
    while (!Q.empty()) {
        int s = Q.front();Q.pop();
        int x = s/m,y = s%m;
        //cout << x << " " << y << endl;
        for (int i = 0;i < 4; i++) {
            int nx = x + mov[i][0],ny = y + mov[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx*m+ny] != '#') {
                int t = nx*m + ny;d[s]++;
                if (vis[t] == 0) {
                    Q.push(nx*m+ny);
                    vis[t] = 1;
                }
            }
            if (d[s] >= 3) ok = 1;
        }
    }
    if (vis[t] == 1 && ok) puts("YES");
    else puts("NO");
	return 0;
}
