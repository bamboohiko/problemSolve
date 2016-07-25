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
int  a[110][110],f[110][110];
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++)
        for (int j = 1;j <= i; j++) scanf("%d",&a[i][j]);
    for (int i = 1;i <= n; i++) f[n][i] = a[n][i];
    for (int i = n;i >= 1; i--)
        for (int j = 1;j <= i; j++)
            f[i][j] = max(f[i+1][j],f[i+1][j+1])+a[i][j];
    printf("%d\n",f[1][1]);
	return 0;
}
