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
double v[10100];
int main() {
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int n;double l;
    while (scanf("%d %lf",&n,&l) != EOF) {
        for (int i = 1;i <= n; i++) {
            scanf("%lf",&v[i]);
            v[i] = l/v[i];
        }
        sort(v+1,v+n+1);
        double ans = 0;
        while (n > 3) {
            if (v[2] + v[2] > v[1] + v[n-1]) {
                ans += v[1] + v[1] + v[n-1] + v[n];
            } else {
                ans += v[1] + v[2] + v[2] + v[n];
            }
            n -= 2;
        }
        if (n == 2) ans += v[2];
        if (n == 3) ans += v[1] + v[2] + v[3];
        printf("%.0lf\n",ceil(ans));
    }
	return 0;
}
