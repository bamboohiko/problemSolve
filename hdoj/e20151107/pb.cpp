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
int a[10][10],c[30];
int n,m,k;
void print() {
    puts("YES");
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j < m; j++)
            printf("%d ",a[i][j]);
        printf("%d\n",a[i][m]);
    }
}
bool dfs(int p) {
    if (p > m*n) {
        print();
        return true;
    }
    int x = (p-1)/m + 1,y = (p-1)%m+1;
    //cout << x << " " << y << endl;
    for (int i = 1;i <= k; i++) {
        if (c[i] && a[x-1][y] != i && a[x][y-1] != i) {
            c[i]--;
            a[x][y] = i;
            if (dfs(p+1)) return true;
            c[i]++;
        }
        if (p == 1)
            while (i < k && c[i+1] == c[i]) i++;
    }
    return false;
}
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 1;i <= k; i++) scanf("%d",&c[i]);
        sort(c+1,c+k+1);
        printf("Case #%d:\n",ca);
        if ((c[1] > ((n*m) >> 1)) || (!dfs(1))) puts("NO");
    }
	return 0;
}
