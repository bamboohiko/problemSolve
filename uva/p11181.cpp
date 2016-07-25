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
double p[30],f[30];
int main() {
    int n,m,T = 1;
    while (scanf("%d %d",&n,&m) != EOF) {
        memset(f,0,sizeof(f));
        if (n == 0 && m == 0) break;
        for (int i = 0;i < n; i++) scanf("%lf",&p[i]);
        int S = (1 << m)-1;double sum = 0;
        while (S < (1 << n)) {
            double ps = 1;
            for (int i = 0;i < n; i++)
                if (S&(1<<i)) ps *= p[i];
                else ps *= (1-p[i]);
            sum += ps;
            for (int i = 0;i < n; i++)
                if (S&(1<<i)) f[i] += ps;
            int x = S &(-S), y = S + x;
            if (x == 0) break;
            S = ((S & ~y) / x >> 1) | y;
        }
        printf("Case %d:\n",T++);
        for (int i = 0;i < n; i++) printf("%.6lf\n",f[i]/sum);
    }
	return 0;
}
