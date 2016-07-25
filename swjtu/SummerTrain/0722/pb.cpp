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
const int inf = 1e9 + 7;
int a[110],f[110];
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        printf("Case %d:\n",ca);
        int n,r = 0;
        f[0] = -inf;
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) {
            scanf("%d",&a[i]);
            f[i] = max(0,f[i-1]) + a[i];
            if (f[i] > f[r]) r = i;
        }
        int l = r;
        while (l > 1 && f[l-1] + a[l] == f[l]) l--;
        printf("%d %d %d\n",f[r],l,r);
    }
	return 0;
}
