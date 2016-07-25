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
int a[1010];
int main() {
    int r,n;
    while (scanf("%d%d",&r,&n) != EOF) {
        if (r == -1 && n == -1) break;
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int d = a[1],ans = 0,rec = 0;
        for (int i = 2;i <= n; i++) {
            if (rec == 0 && a[i] - d > r) {
                ans++;d = a[i-1];rec = 1 - rec;
            }
            if (rec == 1 && a[i] - d > r) {
                d = a[i];rec = 0;
            }
        }
        if (!rec) ans++;
        printf("%d\n",ans);
    }
	return 0;
}

