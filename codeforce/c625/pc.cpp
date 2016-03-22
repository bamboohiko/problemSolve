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
int f[510][510];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int a = 1,b = n*n,ans = 0;
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j < k; j++) f[i][j] = a++;
        for (int j = n;j >= k; j--) f[i][j] = b--;
        ans += f[i][k];
    }
    printf("%d\n",ans);
    for (int i = 1;i <= n; i++) {
        for (int j = 1;j < n; j++) printf("%d ",f[i][j]);
        printf("%d\n",f[i][n]);
    }
	return 0;
}

