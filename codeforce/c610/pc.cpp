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
int a[600][600];
int main() {
    int n;
    scanf("%d",&n);
    a[1][1] = 1;
    for (int k = 0;k < n; k++) {
        int d = 1 << k;
        for (int i = 1;i <= d; i++)
            for (int j = 1;j <= d; j++) {
                a[d+i][j] = a[i][j];a[i][d+j] = a[i][j];
                a[d+i][d+j] = -a[i][j];
            }
    }
    int k = 1 << n;
    for (int i = 1;i <= k; i++) {
        for (int j = 1;j <= k; j++)
            if (a[i][j] == 1) putchar('+');
            else putchar('*');
        puts("");
    }

	return 0;
}
