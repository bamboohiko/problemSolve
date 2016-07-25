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
#define eps 1e-12
#define pi acos(-1.0)
using namespace std;
typedef long long LL;
double f[2000100],p[50],x[50];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 0;i < n; i++) scanf("%lf",&p[i]);
    f[0] = 1;
    for (int j = 1;j < (1<<n); j++) {
        double opp = 0;
        int cou = n;
        for (int i = 0;i < n; i++)
            if ((j&(1<<i)) == 0) {opp += p[i];cou--;}
        if (cou > k) continue;
        for (int i = 0;i < n; i++) {
            if (j&(1<<i) && p[i] > eps) {
                double inc = f[j-(1<<i)]*(p[i]/(opp+p[i]));
                f[j] += inc;x[i] += inc;
            }
        }
        //printf("%d %lf\n",j,f[j]);
    }
    /*
    int S = (1<<k) - 1;
    while(S < (1<<n)) {
        for (int i = 0;i < n; i++) {
            if (S&(1<<i)) x[i] += f[S];
        }
        int x = S&(-S), y = S + x;
        S = ((S & ~y) / x >> 1) | y;
    }
    */
    printf("%lf",x[0]);
    for (int i = 1;i < n; i++) printf(" %lf",x[i]);
    printf("\n");
	return 0;
}
