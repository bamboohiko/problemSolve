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
using namespace std;
int main() {
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF) {
        int sum = 0;
        for (int i = 1;i <= n; i++)
            for (int j = 1;j <= m; j++) {
                scanf("%d",&a[i][j]);
                sum += a[i][j];
            }
        if (n%2) {
            for (int i = 1;i < n;i += 2) {
                for (int i = 1;i < m; i++) putchar('R');puts("D");
                for (int i = 1;i < m; i++) putchar('L');puts("D");
            }
            for (int i = 1;i < m; i++) putchar('R');puts();
        } else if (m%2) {
            for (int i = 1;i < m;i += 2) {
                for (int i = 1;i < n; i++) putchar('D');puts("R");
                for (int i = 1;i < n; i++) putchar('U');puts("R");
            }
            for (int i = 1;i < n; i++) putchar('D');puts();
        } else {
            int locx = 0,locy = 0;a[locx][locy] = inf;
            for (int i = 1;i <= n;i += 2)
                for (int j = 1;j <= m;j += 2)
                    if
    }
	return 0;
}

