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
const double inf = 1e9;
int n;
double l,c,t,vr,vt1,vt2;
double f[110][2],a[110];
double fig(double l,int k) {
    double ans;
    if (k == 0) ans = l/vt2;
    else {
        if (l > c) ans = c/vt1 + (l-c)/vt2;
        else ans = l/vt1;
    }
    return ans;
}
int main() {
    while (scanf("%lf",&l) != EOF) {
        memset(f,0,sizeof(f));
        scanf("%d%lf%lf",&n,&c,&t);
        scanf("%lf%lf%lf",&vr,&vt1,&vt2);
        for (int i = 1;i <= n; i++) {
            scanf("%lf",&a[i]);
            f[i][0] = f[i][1] = inf;
        }
        a[++n] = l;
        f[n][0] = f[n][1] = inf;
        f[0][1] = f[0][0] = 0;
        for (int i = 1;i <= n; i++) {
            for (int j = 0;j < i; j++)
                f[i][0] = min(f[i][0],min(f[j][0]+fig(a[i]-a[j],0),f[j][1]+fig(a[i]-a[j],1)));
            f[i][1] = f[i][0] + t;
            //printf("%.2lf %.2lf\n",f[i][0],f[i][1]);
        }
        if (f[n][0] > l/vr) printf("Good job,rabbit!\n");
        else printf("What a pity rabbit!\n");
    }
	return 0;
}

