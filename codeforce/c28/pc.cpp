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
double f[60][60][60];
double cal[60][60];
int a[60];
void init() {
    for (int i = 0;i <= 50; i++) {
        cal[i][0] = 1;
        for (int j = 1;j <= i; j++)
            cal[i][j] = cal[i-1][j-1] + cal[i-1][j];
    }
}
int main() {
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= m; i++) scanf("%d",&a[i]);
    for (int j = 1;j <= n; j++) f[0][0][j] = j;
    for (int i = 1;i <= m; i++)
        for (int j = 0;j <= n; j++)
            for (int k = 0;k <= n; k++) {
                int mid = min(k*a[i],j);
                for (int c = 0;c <= mid;c++) f[i][j][k] += f[i-1][j-c][k]*pow(i-1,j-c)/pow(i,j)*cal[j][c];
                for (int c = mid+1;c <= j;c++) f[i][j][k] += f[i-1][j-c][(c+a[i]-1)/a[i]]*pow(i-1,j-c)/pow(i,j)*cal[j][c];
            }
    printf("%.20lf\n",f[m][n][0]);
	return 0;
}
