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
int main() {
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    double p,d;int n;
    while (scanf("%lf%lf%d",&p,&d,&n) != EOF) {
        double k,m = 0;int loc = 0;
        for (int i = 1;i <= n; i++) {
            scanf("%lf",&k);
            if (k > m) {
                loc = i;
                m = k;
            }
        }
        if (p*(1-m) > p-d) printf("APP %.2lf\n",p-d);
        else printf("%d %.2lf\n",loc,p*(1-m));
    }
	return 0;
}
